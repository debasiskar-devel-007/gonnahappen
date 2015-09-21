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
    '#title' => t('comments'),
    '#type' => 'textfield',
    '#default_value' => isset($contacts->postedon) ? $contacts->postedon : '',
    '#description' => t('postedon.'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );

$form['enquiry_type'] = array(
    '#title' => t('enquiry_type'),
    '#type' => 'textfield',
    '#default_value' => isset($contacts->enquiry_type) ? $contacts->enquiry_type : '',
    '#description' => t('enquiry_type.'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );




  field_attach_form('contactus', $contacts, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($contacts->contact_id) ? t('Update contact us') : t('Save Contact'),
    ),
    'delete_link' => array(
      '#markup' => isset($contacts->contact_id) ? l(t('Delete'), 'admin/content/contactus/manage/' . $contacts->contact_idcontact_id . '/delete', array('attributes' => array('id' => array('contactus-delete-' . $contacts->contact_id), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/contactus'))) : ''));
  return $form;
}

/**
 * Implements hook_form_validate().
 */
function contactus_form_validate($form, &$form_state) {
}

/**
 * Implements hook_form_submit().
 */
function contactus_form_submit($form, &$form_state) {
  $contactus = entity_ui_form_submit_build_entity($form, $form_state);
    $contactus->save();
  drupal_set_message(t('@first_name contact has been saved.', array('@first_name' => $contactus->first_name)));
  // $form_state['redirect'] = 'admin/content/lawmakers';
  $form_state['redirect'] = 'contactus/' . $contactus->contact_id;

}

/**
 * Confirmation before bulk deleting lawmakers.
 */
function contactus_bulk_delete($form, &$form_state, $lawmakers_ids) {
  $lawmakers_ids = explode('|', $lawmakers_ids);
  $lawmakers = lawmakers_load_multiple($lawmakers_ids);

  $form = array();
  $form_state['lawmakers_ids'] = $lawmakers_ids;

  $variables = array(
    'type' => 'ul',
    'items' => array(),
    'title' => '',
    'attributes' => array(),
  );

  foreach ($lawmakers as $lawmaker) {
    $variables['items'][] = $lawmaker->username;
  }

  $form['summary'] = array(
    '#markup' => theme_item_list($variables),
  );

  return confirm_form($form, t('Delete all lawmakers?'), 'admin/content/contactus', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function contactus_bulk_delete_submit($form, &$form_state) {
  $lawmakers_ids = $form_state['lawmakers_ids'];
  lawmakers_delete_multiple($lawmakers_ids);

  drupal_set_message(t('lawmakers deleted'));
  drupal_goto('admin/content/lawmakers');
}
