<?php
/**
 * @file
 * dashboard.theme.inc
 */

/**
 * Theme lawmaker full page.
 */
function theme_banner_manage_full($variables) {
    $arg=arg();
    $_SERVER['HTTP_REFERER'];//exit;
     $arg[2];//exit;
    global $base_url;
   // print_r($variables['banner_image']);exit;
   if($variables['banner_image']) {
       $image_ids = explode('||', $variables['banner_image']);
       $image_urls = explode('||', $variables['banner_image_url']);
       $image_id_path = array_combine($image_ids,$image_urls);
       $banner_image_url = array();
       if (count($image_id_path > 0)) {
           foreach ($image_id_path as $index => $val) {
               $imgpath = file_load($index)->uri;
               $banner_image_url[$index]['image'] = file_create_url($imgpath);
               $banner_image_url[$index]['image_url'] = $val;
           }
       }


       /*       $image_ids = explode('||', $variables['banner_image']);

              // print_r($image_ids);exit;
              $banner_image_url = array();
              if (count($image_ids > 0)) {
                  foreach ($image_ids as $index => $val) {


                      $imgpath = file_load($val)->uri;
                      $banner_image_url[$val] = file_create_url($imgpath);
                  }
              }*/
   }
    $banner_id= @$variables['banner_id'];
    $output = '';
    $img_listing='';
    $banner = $variables['banner'];
    $img_listing='';
  //  echo count($banner_image_url);exit;
    if(count($banner_image_url)){
        $i=1;
        foreach($banner_image_url as $key=>$img_src){
            $image_urll=$base_url.'/'.$img_src['image_url'];
            $img_src=$img_src['image'];
            $img_listing .='<tr class="odd">
 <td><img style="max-width:200px;max-height:180px;" src="'  . $img_src . ' "></td><td>'.$image_urll.'</td><td>'.l(t('Delete'), 'managebannerdelete/' . $banner_id.'/'.$key).'</td></td> </tr>';


         }

     }
    else{
            $img_listing .='<td colspan="3" align="center" class="no_data">No Banner Image Found !</td>
 </tr>';


    }



    $output .= '<div class="headingtext"><span>Banner Image Listing</span></div>';


    $output .= '<div class="contact-div">';
    $output .= '<div class="contact_meta main_contact"><span class="addimage">'.l(t('Add Image'), 'banner/image/add/' . $banner_id.'/'.$arg[2]).'</span><div class="clearfix"></div>

    <!--<label>Banner Image:</label><span>Operation</span>-->
    <table class="table table-bordered table-hover dataTable sticky-enabled table-select-processed">
        <thead>
            <tr>
                <th>
                    <a href="#" title="sort by Banner Name" class="active">Banner Image</a>
                </th>
                <th>
                    <a href="#" title="sort by Banner Image Url" class="active">Banner Image Url</a>
                </th>

                <th>
                    <a href="#" title="sort by Banner Status" class="active">Operations</a>
                </th>
            </tr>
        </thead>

       <tbody>
 <tbody>'.$img_listing.



'</tbody>

</table>


    </div>';



    // Lazy...









    $output .= '</div>';
    // $output .= '<div class="party">' . $lawmakers->party . ' ' . $lawmakers->state  . '  ' . $lawmakers->district . '</div>';
    return $output;
}
