<?php
/**
 * @file
 * dashboard.theme.inc
 */

/**
 * Theme lawmaker full page.
 */
function theme_event_full($variables) {

  $output = '';
  $event = $variables['event'];
  $create_time= date('m / d / Y , H:i',($event->event_create_time));
  $image_ids=$event->event_banner;
  if($image_ids){
          $imgpath = file_load($image_ids)->uri;
          $banner_image_url = file_create_url($imgpath);
          $img_src='<img src="'.$banner_image_url.'" style="width:150px;height:100px;">';
    }
     else{
            $img_src='No image';
}

  $feature_news_banner_id=$event->featured_news_banner;
   if ($feature_news_banner_id){
          $feature_news_banner_path = file_load($feature_news_banner_id)->uri;
          $feature_news_banner_image_url = file_create_url($feature_news_banner_path);
          $fature_news_banner_src = '<img src="' . $feature_news_banner_image_url . '" style="width:150px;height:100px;">';
    }
    else{
          $fature_news_banner_src='No image';
    }


  $event_status=$event->event_status?'Active':'Deactive';

  $output .= '<div class="contact_meta main_contact">';
  $output .= '<div class="headingtext"><span>Event Details</span></div>';
  $output .= '<div class="contact-div"><label>Event Name:</label><span>'  . trim($event->event_name). '</span></div>';
  $output .= '<div class="contact-div"><label>Event Description :</label><span>'  . trim($event->event_desc)  . '</span></div>';
  $output .= '<div class="contact-div"><label>Event Banner :</label><span>'.$img_src.'</span></div><br/>';
  $output .= '<div class="contact-div"><label>Featured News Banner :</label><span>'  . $fature_news_banner_src  . '</span></div>';
  $output .= '<div class="contact-div"><label>Featured News Content :</label><span>'  . trim($event->featured_news_content)  . '</span></div>';
  $output .= '<div class="contact-div"><label>Event Status :</label><span>'  . $event_status.'</span></div>';
  $output .= '<div class="contact-div"><label>Event Created On :</label><span>'  .date('m / d / Y , H:i',($event->event_create_time))  . '</span></div>';







  // $output .= '<div class="party">' . $lawmakers->party . ' ' . $lawmakers->state  . '  ' . $lawmakers->district . '</div>';

  if (user_access('administer event entities') && isset($event->event_id)) {
      $edit_link='';
    //$edit_link = '<ul class="tabs primary"><li>';
    $edit_link .= l(t('Edit'), 'admin/content/event/manage/' . $event->event_id, array('attributes' => array('class' => 'admin-edit-link viewdeletebtn2')));
    //$edit_link .= '</li></ul>';
    $output .= $edit_link;
  }

  $output .= '</div>';

  return $output;
}
