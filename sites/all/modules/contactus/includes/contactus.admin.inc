<?php
/**
 * @file
 * The file for admin forms and functionality for the lawmakers entity
 */

/**
 * Implements hook_form().
 */
function contactus_form($form, &$form_state, $contacts = NULL) {
    $form = array();

    $form['first_name'] = array(
        '#title' => t('First Name'),
        '#type' => 'textfield',
        '#default_value' => isset($contacts->first_name) ? $contacts->first_name : '',
        '#description' => t('First name .'),
        '#required' => TRUE,
        '#maxlength' => 255,
    );

    $form['last_name'] = array(
        '#title' => t('Last Name'),
        '#type' => 'textfield',
        '#default_value' => isset($contacts->last_name) ? $contacts->last_name : '',
        '#description' => t('last name.'),
        '#required' => TRUE,
        '#maxlength' => 255,
    );

    $form['email'] = array(
        '#title' => t('Email'),
        '#type' => 'textfield',
        '#default_value' => isset($contacts->email) ? $contacts->email : '',
        '#description' => t('Email.'),
        '#required' => TRUE,
        '#maxlength' => 255,
    );

    $form['phone'] = array(
        '#title' => t('phone'),
        '#type' => 'textfield',
        '#default_value' => isset($contacts->phone) ? $contacts->phone : '',
        '#description' => t('phone.'),
        '#required' => TRUE,
        '#maxlength' => 255,
    );

    $form['comments'] = array(
        '#title' => t('comments'),
        '#type' => 'textfield',
        '#default_value' => isset($contacts->comments) ? $contacts->comments : '',
        '#description' => t('comments.'),
        '#required' => TRUE,
        '#maxlength' => 255,
    );

    $form['postedon'] = array(
        '#title' => t('postedon'),
        '#type' => 'hidden',
        '#default_value' => isset($contacts->postedon) ? $contacts->postedon : '',
        '#description' => t('postedon.'),
        '#required' => TRUE,
        '#maxlength' => 255,
        '#value'=>time()
    );

/*$form['enquiry_type'] = array(
    '#title' => t('enquiry_type'),
    '#type' => 'textfield',
    '#default_value' => isset($contacts->enquiry_type) ? $contacts->enquiry_type : '',
    '#description' => t('enquiry_type.'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );*/

    $options = array();
    $options["Site_Visitor"] = "Site Visitor";
    $options["Event_Poster"] = "Event Poster";
    $options["Ticket_Sales"] = "Ticket Sales";
    $options["Tournament_Enquiry"] = "Tournament Enquiry";
    $options["General_Question"] = "General Question ";


    $form['enquiry_type'] = array(
        '#title' => t('Enquiry Type'),
        '#type' => 'checkboxes',
        '#description' => t(''),
        '#options' => $options,
        '#required' => TRUE,
        '#default_value' => isset($contacts->enquiry_type) ? explode('|',$contacts->enquiry_type) : ''
    );
    $form['search_tag'] = array(
        '#title' => t('search_tags'),
        '#type' => 'hidden',
        '#description' => t(''),
        //'#options' => $options,
        //'#required' => TRUE,
        //'#default_value' => array("1", "2", "3","4")
    );



    field_attach_form('contactus', $contacts, $form, $form_state);

    $form['actions'] = array(
        '#type' => 'actions',
        'submit' => array(
            '#type' => 'submit',
            '#value' => isset($contacts->contact_id) ? t('Update contact us') : t('Save Contact'),
        ),
        'delete_link' => array(
            '#markup' => isset($contacts->contact_id) ? l(t('Delete'), 'admin/content/contactus/manage/' . $contacts->contact_id . '/delete', array('attributes' => array('id' => array('contactus-delete-' . $contacts->contact_id), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/contactus'))) : ''));
    return $form;
}

/**
 * Implements hook_form_validate().
 */
function contactus_form_validate($form, &$form_state) {


    $mail = $form_state['values']['email'];
    if (!valid_email_address($mail)) {
        form_set_error('[email]', t('The email address appears to be invalid.'));
    }



}

/**
 * Implements hook_form_submit().
 */
function contactus_form_submit($form, &$form_state) {

    $form_state['values']['enquiry_type']=implode("|",$form_state['values']['enquiry_type']);
    $form_state['values']['search_tag']=$form_state['values']['enquiry_type'].$form_state['values']['first_name'].$form_state['values']['last_name'];
    // var_dump($form_state['values']);
    // exit;
    $contactus = entity_ui_form_submit_build_entity($form, $form_state);
    $contactus->save();
    drupal_set_message(t('@first_name contact has been saved.', array('@first_name' => $contactus->first_name)));
    // $form_state['redirect'] = 'admin/content/lawmakers';
    $form_state['redirect'] = 'contactus/' . $contactus->contact_id;

}

/**
 * Confirmation before bulk deleting lawmakers.
 */
function contactus_bulk_delete($form, &$form_state, $contact_ids) {
    $contact_ids = explode('|', $contact_ids);
    $contacts = contactus_load_multiple($contact_ids);

    $form = array();
    //$form_state['contact_ids'] = $contact_ids;
    //var_dump($form_state['contact_ids']);
    foreach($contact_ids as $cid){

        $form_state['contact_ids'][]=str_replace('contact_id-','',$cid);

    }

    //var_dump($form_state['contact_ids']);

    $variables = array(
        'type' => 'ul',
        'items' => array(),
        'title' => '',
        'attributes' => array(),
    );

    foreach ($contacts as $contact) {
        echo $variables['items'][] = $contact->first_name;
    }

    $form['summary'] = array(
        '#markup' => theme_item_list($variables),
    );

    return confirm_form($form, t('Delete all contacts?'), 'admin/content/contactus', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function contactus_bulk_delete_submit($form, &$form_state) {
    $contact_ids = $form_state['contact_ids'];
    //var_dump($contact_ids);
    //exit;
    contactus_delete_multiple($contact_ids);

    drupal_set_message(t('contact deleted'));
    drupal_goto('admin/content/contactus');
}
