<?php
/**
 * @file
 * The file for admin forms and functionality for the lawmakers entity
 */

/**
 * Implements hook_form().
 */
function event_form($form, &$form_state, $event = NULL) {
    $form = array();
    $heading= isset($event->event_id) ? t("Edit Event") : t("Add Event");
    $form['#attributes']=array('class'=>'admin-form');
    $form['#attributes']['enctype'] = 'multipart/form-data';

    $form['event_name'] = array(
    '#title' => t('Event Name'),
    '#type' => 'textfield',
    '#default_value' => isset($event->event_name) ? $event->event_name : '',
    '#required' => TRUE,
    '#maxlength' => 255,
    '#prefix' => '<div class="headingtext"><span>'.$heading.'</span></div>',
  );
    $form['event_desc'] = array(
        '#title' => t('Event Decription'),
        '#type' => 'textarea',
        '#default_value' => isset($event->event_name) ? $event->event_name : '',
        '#required' => TRUE,
/*        '#maxlength' => 255,*/
    );
    $form['event_banner'] = array(
        '#title' => t('Event Banner'),
        '#type' => 'managed_file',
        '#name' => 'event_banner',
        '#default_value' => isset($event->event_banner) ? $event->event_banner : '',
        '#description' => t('(Upload banner size width 1920px and height 595px)'),
/*        '#required' => TRUE,*/
        '#upload_validators' => array(
            'file_validate_extensions' => array('gif png jpg jpeg'),
            // Pass the maximum file size in bytes
            'file_validate_size' => array(MAX_FILE_SIZE*1024*1024),
        ),
        '#upload_location' => 'public://event/',
    );
    $form['featured_news_banner'] = array(
        '#title' => t('Featured New Banner'),
        '#type' => 'managed_file',
        '#name' => 'featured_news_banner',
        '#default_value' => isset($event->featured_news_banner) ? $event->featured_news_banner : '',
        '#description' => t('(Upload banner size width 728px and height 318px)'),
        /*        '#required' => TRUE,*/
        '#upload_validators' => array(
            'file_validate_extensions' => array('gif png jpg jpeg'),
            // Pass the maximum file size in bytes
            'file_validate_size' => array(MAX_FILE_SIZE*1024*1024),
        ),
        '#upload_location' => 'public://event/featured/',
    );
    $form['featured_news_content'] = array(
        '#title' => t('Featured News Content'),
        //'#id'=>'featured_news_content',
        '#type' => 'textarea',
        '#default_value' => isset($event->featured_news_content) ? $event->featured_news_content : '',
        '#required' => TRUE,
        //'#format'=>'full_html'
/*        '#maxlength' => 255,*/
    );

    $form['event_create_time'] = array(
        '#title' => t('Event Create Time'),
        '#type' => 'hidden',
        '#default_value' => isset($event->event_create_time) ? $event->event_create_time : '',
        '#description' => t(''),
        '#required' => TRUE,
        '#maxlength' => 255,
        '#value'=>time()
    );

    $options = array();
    $options["checked"] = 1;
    $form['event_status'] = array(
        '#title' => t('Event Status'),
        '#type' => 'checkbox',
        '#description' => t(''),
        '#default_value'=>isset($event->event_status) ? $event->event_status : 0,
    );
    $form['photo_video'] = array(
        '#title' => t('Photo Video'),
        '#type' => 'hidden',
        '#name' => 'photo_video',
        '#default_value' =>'',
        '#description' => t(''),
     );

    $form['search_tag'] = array(
        '#title' => t('search_tags'),
        '#type' => 'hidden',
        '#description' => t(''),
        //'#options' => $options,
        //'#required' => TRUE,
        //'#default_value' => array("1", "2", "3","4")
    );
    field_attach_form('event', $event, $form, $form_state);
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($event->event_id) ? t('Update Event') : t('Save Event'),
    ),
    'delete_link' => array(
      '#markup' => isset($event->event_id) ? l(t('Delete'), 'admin/content/event/manage/' . $event->event_id . '/delete', array('attributes' => array('id' => array('event-delete-' . $event->event_id), 'class' => array('button remove deletebtn')), 'query' => array('destination' => 'admin/content/event'))) : ''));
  return $form;
}

/**
 * Implements hook_form_validate().
 */
function event_form_validate($form, &$form_state) {


    /*$mail = $form_state['values']['email'];
    if (!valid_email_address($mail)) {
        form_set_error('[email]', t('The email address appears to be invalid.'));
    }*/



}

/**
 * Implements hook_form_submit().
 */
function event_form_submit($form, &$form_state) {

    $form_state['values']['search_tag']=$form_state['values']['event_name'];
   // var_dump($form_state['values']);
   // exit;
    $event = entity_ui_form_submit_build_entity($form, $form_state);
    $event->save();
  drupal_set_message(t('@event_name event has been saved.', array('@event_name' => $event->event_name)));
  // $form_state['redirect'] = 'admin/content/lawmakers';
  $form_state['redirect'] = 'event/' . $event->event_id;

}

/**
 * Confirmation before bulk deleting lawmakers.
 */
function event_bulk_delete($form, &$form_state, $event_ids) {

    $event_ids = explode('|', $event_ids);

  $form = array();
   //$form_state['contact_ids'] = $contact_ids;
    //var_dump($form_state['contact_ids']);
    foreach($event_ids as $cid){

        $form_state['event_ids'][]=str_replace('event_id-','',$cid);

    }
    $events = event_load_multiple($form_state['event_ids']);

 //   var_dump($form_state['event_ids']);exit;

  $variables = array(
    'type' => 'ul',
    'items' => array(),
    'title' => '',
    'attributes' => array(),
  );

  foreach ($events as $event) {
     $variables['items'][] = $event->event_name;
  }
    $form['#prefix'] ='<div class="contact_meta main_confirmation confirm-delet">';
    $form['#suffix'] ='</div>';

  $form['summary'] = array(
    '#markup' => theme_item_list($variables),
  );

    $cancel=''.t("Cancel");
    $yes=t("Delete all");
    $heading='<div class="headingconfirmtext"><span>'.t("Do You want to delete these items ?").'</span></div>';
    return confirm_form($form,t('Delete all events ?'),'admin/content/event',$heading ,$yes , $cancel);

    //return confirm_form($form, t('Delete all events?'), 'admin/content/event', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function event_bulk_delete_submit($form, &$form_state) {
  $event_ids = $form_state['event_ids'];
    //var_dump($contact_ids);
    //exit;
    event_delete_multiple($event_ids);

  drupal_set_message(t('event deleted'));
  drupal_goto('admin/content/event');
}
