<?php
/**
 * @file
 * contactus.theme.inc
 */

/**
 * Theme lawmaker full page.
 */
function theme_contactus_full($variables) {
  $output = '';
  $contacts = $variables['contact'];
  /*$lawmakers_image_size = '200x250';
  $image_data = array(
    'path' => drupal_get_path('module', 'lawmakers') . '/images/' . $lawmakers_image_size . '/' . $lawmakers->bioguide_id . '.jpg',
  );*/

  $output .= '<div class="contact_meta">';

  // Lazy...

  $output .= '<div class="contact-name">'  . trim($contacts->first_name)  . ' ' . trim($contacts->last_name) . '</div>';
  $output .= '<div class="contact-email">'  . trim($contacts->email)  . '</div>';
  $output .= '<div class="contact-phone">'  . trim($contacts->phone)  . '</div>';
  $output .= '<div class="contact-comments">'  . trim($contacts->comments)  . '</div>';
  $output .= '<div class="contact-postedon">'  . trim(date('m / d / Y , H:i',($contacts->postedon)))  . '</div>';

  $enquiry_type=explode('|',$contacts->enquiry_type);
  //var_dump($enquiry_type);
  foreach($enquiry_type as $val){


    if(strlen($val) > 1){
      //var_dump($val);

      $output .= '<div class="contact-enquiry_type">'  . trim( str_replace('_'," ",$val))  . '</div>';
    }



  }

  //$output .= '<div class="contact-enquiry_type">'  . trim($contacts->enquiry_type)  . '</div>';
  // $output .= '<div class="party">' . $lawmakers->party . ' ' . $lawmakers->state  . '  ' . $lawmakers->district . '</div>';

  if (user_access('administer contact entities') && isset($contacts->contact_id)) {
    $edit_link = '<ul class="tabs primary"><li>';
    $edit_link .= l(t('Edit'), 'admin/content/contactus/manage/' . $contacts->contact_id, array('attributes' => array('class' => 'admin-edit-link')));
    $edit_link .= '</li></ul>';
    $output .= $edit_link;
  }

  $output .= '</div>';

  return $output;
}
