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
    if($arg[2]){
        $arg_link=$arg[2];
    }
    if($arg[3]){
        $arg_link=$arg[2].'/'.$arg[3];
    }

    $arg[2];//exit;
    global $base_url;
   //print_r($variables['banner_image']);exit;
   if(!empty($variables['banner_image']) && !empty($variables['banner_image_url'])) {
       $image_ids = explode('||', $variables['banner_image']);
       $image_urls = explode('||', $variables['banner_image_url']);
       $banner_image_url = array();

       if(count($image_ids) >= count($image_urls)){
            foreach($image_urls as $key=>$val){
                $imgpath = file_load($image_ids[$key])->uri;
                $banner_image_url[$image_ids[$key]]['image'] = file_create_url($imgpath);
                $banner_image_url[$image_ids[$key]]['image_url'] = $val;
            }
       }else{
           foreach($image_ids as $key=>$val){
               $imgpath = file_load($image_ids[$key])->uri;
               $banner_image_url[$val]['image'] = file_create_url($imgpath);
               $banner_image_url[$val]['image_url'] = $image_urls[$key];
           }
       }

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
    $output .= '<div class="contact_meta main_contact"><span class="addimage">'.l(t('Add Image'), 'banner/image/add/' . $banner_id.'/'.$arg_link).'</span><div class="clearfix"></div>

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
