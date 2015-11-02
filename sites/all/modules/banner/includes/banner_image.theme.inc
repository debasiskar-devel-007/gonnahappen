<?php
/**
 * @file
 * The file for admin forms and functionality for the lawmakers entity
 */

/**
 * Implements hook_form().
 */
function theme_banner_manage_upload() {
global $entity;
   // $output='new';
    $elements = entity_form("banner");
    $form = drupal_render($elements);

/*    $output='';
    $output .= '<div class="contact_meta main_contact">';
    $output .= '<div class="headingtext"><span>Banner Image</span></div>';

    $form = array();
    $form['#attributes']=array('class'=>'admin-form');
    $form['#attributes']['enctype'] = 'multipart/form-data';

    //echo current_path();

    $form['banner_image'] = array(
        '#title' => t('Banner Image'),
        '#type' => 'managed_file',
        '#multiple' => TRUE,
        //'#name' => 'banner_image',
        //'#default_value' => isset($banner->banner_image) ? $banner->banner_image : '',
        '#description' => t('Banner Image.'),
        '#required' => TRUE,
        '#upload_validators' => array(
            'file_validate_extensions' => array('gif png jpg jpeg'),
            // Pass the maximum file size in bytes
            'file_validate_size' => array(MAX_FILE_SIZE*1024*1024),
        ),
        '#upload_location' => 'public://banner/',
        '#attributes' => array('multiple' => 'multiple'),

    );
    $form['actions'] = array(
        '#type' => 'actions',
        'submit' => array(
            '#type' => 'submit',
            '#value' => t('Upload Banner'),
        ),);

        $output .=$form.'</div>';*/
return $form;
}
function banner1_form_validate($form, &$form_state) {





}

function banner1_form_submit($form, &$form_state)
{
    global $base_url;
      $form_state['values']['search_tag'] = $form_state['values']['banner_name'];
    $banner= entity_ui_form_submit_build_entity($form, $form_state);
     $banner->save();
    drupal_set_message(t('@banner_name banner has been saved.', array('@banner_name' => $banner->banner_name)));
    $form_state['redirect'] = 'admin/content/banner/';
}
