<?php
/**
 * @file
 * dashboard.theme.inc
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
  $output .= '<div class="contact_meta main_contact">';
  $output .= '<div class="headingtext"><span>Contact Details</span></div>';




  // Lazy...

  $output .= '<div class="contact-div"><label>Full Name :</label><span>'  . trim($contacts->first_name)  . ' ' . trim($contacts->last_name) . '</span></div>';
  $output .= '<div class="contact-div"><label>Email :</label><span>'  . trim($contacts->email)  . '</span></div>';
  $output .= '<div class="contact-div"><label>Phone Number :</label><span>'  . trim($contacts->phone)  . '</span></div>';
  $output .= '<div class="contact-div"><label>Comments :</label><span>'  . trim($contacts->comments)  . '</span></div>';
  $output .= '<div class="contact-div"><label>Contacts On :</label><span>'  . trim(date('m / d / Y , H:i',($contacts->postedon)))  . '</span></div>';
  $output .='<div class="contact-div"><label>Enquiry Type :</label>';
  $enquiry_type=explode('|',$contacts->enquiry_type);
  //var_dump($enquiry_type);
  foreach($enquiry_type as $val){


    if(strlen($val) > 1){
      //var_dump($val);

      $output .= '<span>'  . trim( str_replace('_'," ",$val))  . '</span>,';
    }



  }

  $output .= '</div>';
  // $output .= '<div class="party">' . $lawmakers->party . ' ' . $lawmakers->state  . '  ' . $lawmakers->district . '</div>';

  if (user_access('administer contact entities') && isset($contacts->contact_id)) {
    //$edit_link = '<ul class="tabs primary"><li>';
    $edit_link = l(t('Edit'), 'admin/content/contactus/manage/' . $contacts->contact_id, array('attributes' => array('class' => 'admin-edit-link viewdeletebtn2')));
    //$edit_link .= '</li></ul>';
    $output .= $edit_link;
  }

  $output .= '</div>';

  return $output;
}
