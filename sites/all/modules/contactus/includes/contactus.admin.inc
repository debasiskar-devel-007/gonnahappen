<?php
/**
 * @file
 * The file for admin forms and functionality for the lawmakers entity
 */

/**
 * Implements hook_form().
 */
function contactus_form($form, &$form_state, $contacts = NULL) {

  /*  echo '<div style="color:red;">';*/
    $form = array();
    $heading= isset($contacts->contact_id) ? t("Edit contact") : t("Add Contact");
	$form['#attributes']=array('class'=>'admin-form');
    //echo current_path();

   /* $form['prefix']='<div style="color:red;">';*/
    $form['first_name'] = array(
        '#title' => t('First Name'),
        '#type' => 'textfield',
        '#default_value' => isset($contacts->first_name) ? $contacts->first_name : '',
        '#description' => t(''),
        '#required' => TRUE,
        '#maxlength' => 255,
		'#markup'=>"<div>asd</div>",
        '#prefix' => '<div class="headingtext"><span>'.$heading.'</span></div>',
		'#attributes'=>array('class'=>'form-control')
    );

    $form['last_name'] = array(
        '#title' => t('Last Name'),
        '#type' => 'textfield',
        '#default_value' => isset($contacts->last_name) ? $contacts->last_name : '',
        '#description' => t(''),
        '#required' => TRUE,
        '#maxlength' => 255,
    );

    $form['email'] = array(
        '#title' => t('Email'),
        '#type' => 'textfield',
        '#default_value' => isset($contacts->email) ? $contacts->email : '',
        '#description' => t(''),
        '#required' => TRUE,
        '#maxlength' => 255,
    );

    $form['phone'] = array(
        '#title' => t('phone'),
        '#type' => 'textfield',
        '#default_value' => isset($contacts->phone) ? $contacts->phone : '',
        '#description' => t(''),
        '#required' => TRUE,
        '#maxlength' => 255,
    );


    $form['postedon'] = array(
        '#title' => t('postedon'),
        '#type' => 'hidden',
        '#default_value' => isset($contacts->postedon) ? $contacts->postedon : '',
        '#description' => t(''),
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
    $options["Partner_or_Affiliate_Inquiries"] = "Partner or Affiliate Inquiries ";
    $options["Advertising_inquires_or_questions"] = "Advertising inquires or questions ";


    $form['enquiry_type'] = array(
        '#title' => t('Enquiry Type'),
        '#type' => 'checkboxes',
        '#description' => t(''),
        '#options' => $options,
        '#required' => TRUE,
        '#default_value' => isset($contacts->enquiry_type) ? explode('|',$contacts->enquiry_type) : ''
    );



    $form['comments'] = array(
        '#title' => t('comments'),
        '#type' => 'textarea',
        '#default_value' => isset($contacts->comments) ? $contacts->comments : '',
        '#description' => t(''),
        '#required' => TRUE,
        '#maxlength' => 255,
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
        '#prefix'=>'<div class="clear"></div>',
        'submit' => array(
            '#type' => 'submit',
            '#value' => isset($contacts->contact_id) ? t('Update contact us') : t('Save Contact'),
        ),





        'delete_link' => array(
            '#markup' => isset($contacts->contact_id) ? l(t('Delete'), 'admin/content/contactus/manage/' . $contacts->contact_id . '/delete', array('attributes' => array('id' => array('contactus-delete-' . $contacts->contact_id), 'class' => array('button remove deletebtn')), 'query' => array('destination' => 'admin/content/contactus'))) : ''));

    if(current_path() == 'contact-us')
    {
        $form['first_name']['#attributes']['placeholder'] =t('First Name');
        $form['last_name']['#attributes']['placeholder'] =t('Last Name');
        $form['email']['#attributes']['placeholder'] =t('Email');
        $form['phone']['#attributes']['placeholder'] =t('Phone');
        $form['comments']['#attributes']['placeholder'] =t('Comments');
        $form['actions']['submit']['#value']='SUBMIT INQUIRY';
    }


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
function contactus_form_submit($form, &$form_state)
{
    global $base_url;

    $form_state['values']['enquiry_type'] = implode("|", $form_state['values']['enquiry_type']);
    $form_state['values']['search_tag'] = $form_state['values']['enquiry_type'] . $form_state['values']['first_name'] . $form_state['values']['last_name'];
    $contactus = entity_ui_form_submit_build_entity($form, $form_state);
    if (current_path() == 'contact-us'){
        $entity_type = 'contactus';
        $entity = entity_create($entity_type, array());
        $entity->first_name = $form_state['values']['first_name'];
        $entity->last_name = $form_state['values']['last_name'];
        $entity->email = $form_state['values']['email'];
        $entity->phone = $form_state['values']['phone'];
        $entity->postedon = $form_state['values']['postedon'];
        $entity->comments = $form_state['values']['comments'];
        $entity->enquiry_type = $form_state['values']['enquiry_type'];
        $entity->search_tag = $form_state['values']['search_tag'];
        $entity->save();

        $form_state['redirect'] = url($base_url."/".current_path()."?submit=saved");


    }
else{
    // exit;
    $contactus->save();
//exit;
    drupal_set_message(t('@first_name contact has been saved.', array('@first_name' => $contactus->first_name)));
    // $form_state['redirect'] = 'admin/content/lawmakers';
    $form_state['redirect'] = 'contactus/' . $contactus->contact_id;

}

    //echo $_GET['submit'];exit;


}
/*function popup()
{
    $html='<div id="popup1" class="overlay">
	<div class="popup">
		<h2>Here i am</h2>
		<a class="close" href="#">×</a>
		<div class="content">
Thanks for pop me out of that button, but now i\'m done so you can close this window.
		</div>
	</div>
</div>';
    return $html;

}*/
/**
 * Confirmation before bulk deleting lawmakers.
 */

function contactus_bulk_delete($contact_ids,$form, &$form_state) {
     $contact_ids = explode('|', $contact_ids);
     $form = array();
    foreach($contact_ids as $cid){

        $form_state['contact_ids'][]=str_replace('contact_id-','',$cid);

    }
    $contacts = contactus_load_multiple($form_state['contact_ids']);
    $variables = array(
        'type' => 'ul',
        'items' => array(),
        'title' => '',
        'attributes' => array(),
    );

    foreach ($contacts as $contact) {
         $variables['items'][] = $contact->first_name;
    }

    /*    $form['summary'] = array(
            '#markup' => theme_item_list($variables),
        );*/

    // print_r($contacts);exit;
    return confirm_form($form, t('Delete all contacts?'), 'admin/content/contactus', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function contactus_bulk_delete_submit($form, &$form_state) {
    $contact_ids = $form_state['contact_ids'];
    contactus_delete_multiple($contact_ids);

    drupal_set_message(t('contact deleted'));
    drupal_goto('admin/content/contactus');
}
