<?php
/**
 * @file
 * dashboard.theme.inc
 */

/**
 * Theme lawmaker full page.
 */
function theme_banner_full($variables) {

    $output = '';
    $banner = $variables['banner'];
    /*$lawmakers_image_size = '200x250';
    $image_data = array(
      'path' => drupal_get_path('module', 'lawmakers') . '/images/' . $lawmakers_image_size . '/' . $lawmakers->bioguide_id . '.jpg',
    );*/
    $output .= '<div class="contact_meta main_contact">';
    $output .= '<div class="headingtext"><span>Banner Details</span></div>';




    // Lazy...

    $output .= '<div class="contact-div"><label>Banner Name:</label><span>'  . trim($banner->banner_name) . '</span></div>';
    $output .= '<div class="contact-div"><label>Banner Help Text :</label><span>'  . trim($banner->banner_help_text)  . '</span></div>';
    $output .= '<div class="contact-div"><label>Banner Image :</label><span>'  . trim($banner->banner_image)  . '</span></div>';

    $output .= '<div class="contact-div"><label>Banner On :</label><span>'  . trim(date('m / d / Y , H:i',($banner->banner_upload_time)))  . '</span></div>';







    $output .= '</div>';
    // $output .= '<div class="party">' . $lawmakers->party . ' ' . $lawmakers->state  . '  ' . $lawmakers->district . '</div>';

    if (user_access('administer banner entities') && isset($banner->banner_id)) {
        //$edit_link = '<ul class="tabs primary"><li>';
        $edit_link = l(t('Edit'), 'admin/content/banner/manage/' . $banner->banner_id, array('attributes' => array('class' => 'admin-edit-link viewdeletebtn2')));
        //$edit_link .= '</li></ul>';
        $output .= $edit_link;
    }

    $output .= '</div>';

    return $output;
}
