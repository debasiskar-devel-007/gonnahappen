<?php
/**
 * @file
 * dashboard.theme.inc
 */

/**
 * Theme lawmaker full page.
 */
function theme_banner_manage_full($variables) {

   // print_r($variables['banner_image']);exit;
   if($variables['banner_image']) {
       $image_ids = explode('||', $variables['banner_image']);

       // print_r($image_ids);exit;
       $banner_image_url = array();
       if (count($image_ids > 0)) {
           foreach ($image_ids as $index => $val) {


               $imgpath = file_load($val)->uri;
               $banner_image_url[$val] = file_create_url($imgpath);
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

         foreach($banner_image_url as $key=>$img_src){
             $img_listing .='<tr class="odd">
 <td><img style="max-width:200px;max-height:180px;" src="'  . $img_src . ' "></td><td>'.l(t('Delete'), 'managebannerdelete/' . $banner_id.'/'.$key).'</td></td> </tr>';


         }

     }
    else{
            $img_listing .='<td colspan="2" align="center" class="no_data">No Banner Image Found !</td>
 </tr>';


    }



    $output .= '<div class="headingtext"><span>Banner Image Listing</span></div>';


    $output .= '<div class="contact-div">';
    $output .= '<div class="contact_meta main_contact"><span class="addimage">'.l(t('Add Image'), 'banner/image/add/' . $banner_id).'</span><div class="clearfix"></div>

    <!--<label>Banner Image:</label><span>Operation</span>-->
    <table class="table table-bordered table-hover dataTable sticky-enabled table-select-processed">
        <thead>
            <tr>
                <th>
                    <a href="#" title="sort by Banner Name" class="active">Banner Image</a>
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
