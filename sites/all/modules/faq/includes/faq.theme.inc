<?php
define('TOTAL_ITEMS_PER_PAGE_FAQ1',1);
define('FRONTEND_FAQ_EDIT', '/admin/content/faq/manage/');
/**
 * @file
 * dashboard.theme.inc
 */

/**
 * Theme frontend full page.
 */



function theme_faq_full($variables) {
    global  $user;
    // echo   $user->uid ;exit;

    $theme_path=drupal_get_path('theme', 'frontendtheme');//exit;

    global $base_url;
    module_load_include('module', 'dynamiccontent');
    if (module_exists('dynamiccontent')) {

        $hometopeditimgpath = editIcon(10);
    }
    $old_revision = entity_load_single('banner',  10);
    $variables=array('banner_image'=>$old_revision->banner_image,'banner_image_url'=>$old_revision->banner_image_url);
    if($variables['banner_image']) {
        $image_ids = explode('||', $variables['banner_image']);
        $image_urls = explode('||', $variables['banner_image_url']);
        $image_id_path = array_combine($image_ids,$image_urls);
        $banner_image_url = array();
        if (count($image_id_path > 0)) {
            foreach ($image_id_path as $index => $val) {
                $imgpath = file_load($index)->uri;
                $banner_image_url[file_create_url($imgpath)] = $val;
            }
        }
    }
    $hometopeditimgpath='';
    if($user->roles[4]=='Site Admin'||$user->roles[3]=='administrator') {
        $hometopeditimgpath = '<img  src="' . $theme_path . '/images/pencil.png" id="home_top_edit1" class="editicon home_top_edit" alt="#">';
        $hometopeditimgpath = l($hometopeditimgpath, 'managebanner/10/faq', array('html' => true));
    }

    $img_listing='';
    if(count($banner_image_url)){
        $i=1;
        foreach($banner_image_url as $key=>$img_src){
            //echo $img_src;
            $img_listing .='<div class="item home_banner_image homebanner">
        <a  href="'.$base_url.'/'.$img_src.'"><img src="'.$key.'" alt=""></a>

       </div>';

        }





//echo $img_listing_center;exit;



        $banner_id= @$variables['banner_id'];
        $output = '';
        $banner = $variables['banner'];
        $imgcarausel='';


        while($i<=count($banner_image_url))
        {
            $imgcarausel .= '<li data-target="#myCarousel" data-slide-to="'.$i.'" class="carsol"></li>';
            $i++;
        }

    }



    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'faq');

    $query->propertyOrderBy('priority');



    $page=$query->pager(TOTAL_ITEMS_PER_PAGE_FAQ1);

    $result = $query->execute();
    //var_dump($result);
    $faq_results = !empty($result['faq']) ? $result['faq'] : array();
    $faq_array = !empty($faq_results) ? faq_load_multiple(array_keys($faq_results)) : array();
    $faq_listing='';
    if(count($faq_array)) {
        foreach ($faq_array as $faq_id => $faq) {
            $destination='faq';
            $edit='';
            if($user->uid==2||$user->uid==3) {

                $edit = l('<img src="' . $base_url . '/' . $theme_path . '/images/edit-pencil.png" class="dynamicconten_change" alt="#">', FRONTEND_FAQ_EDIT . $faq_id, array('html' => true, 'query' => array('destination' => $destination)));
            }
            $faq_listing .= '<div class="faqleftblock1">'.$edit.'
        	<h1>'.$faq->question.'</h1>
	'.$faq->answer.'</div>
		<div class="clearfix"></div>
        <div class="dotted"></div>';


        }
    }
    $faq_listing .=   theme('pager');
 $faq_listing;


    $output = '<div class="container-fluid banner-wrapper">
	<div class="row">'
        .$hometopeditimgpath
        .'<div id="myCarousel" class="carousel slide" data-ride="carousel"
    <!-- Indicators -->


    <!-- Wrapper for slides -->
    <div class="carousel-inner" role="listbox">'.$img_listing.'</div>

    <!-- Left and right controls -->

  </div>
    </div>
</div>




<div class="container faqblck3">
	<div class="row">
    	<div class="col-lg-8  col-lg-offset-0 col-md-10 col-md-offset-1 col-sm-12 col-sm-offset-0 col-xs-12 col-xs-offset-0 faqleftblock">
'.$faq_listing.'		<div class="clearfix"></div>
		<div class="clearfix"></div>
		</div>
        <div class="col-lg-4 col-lg-offset-0 col-md-6 col-md-offset-3 col-sm-8 col-sm-offset-2 col-xs-10 col-xs-offset-1 hmblck3rhtside">
        	<h1>AD space</h1><div class="clearfix"></div>
            <div class="col-lg-12 col-md-12 col-sm-12 ol-xs-12 hmblck3rhtsideblck1">
            	<h1>My Account</h1>
                <ul class="nav nav-tabs">
                    <li class="active"><a data-toggle="tab" href="#sitefan">Site Fan</a></li>
                    <li><a data-toggle="tab" href="#eventtype">Event Type</a></li>
                    <li><a data-toggle="tab" href="#tournament">Tournament<br> User</a></li>
                  </ul>
					<div class="tab-content">
                    <div id="sitefan" class="tab-pane fade in active">
                      <h1>Hello, <a href="#">New User</a></h1>
                      <h2>Sign In Or Create An Account</h2>
                    </div>
                    <div id="eventtype" class="tab-pane fade">
                       <h1>Hello, <a href="#">New User</a></h1>
                      <h2>Sign In Or Create An Account</h2>
                    </div>
                    <div id="tournament" class="tab-pane fade">
                       <h1>Hello, <a href="#">New User</a></h1>
                      <h2>Sign In Or Create An Account</h2>
                    </div>
                    <div id="menu3" class="tab-pane fade">
                      <h3>Menu 3</h3>
                      <p>Eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo.</p>
                    </div>
                  </div>
            </div>
            <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 hmblck3rhtsideblck2">
            	<h1>News</h1>
                <ul class="nav nav-tabs">
					<li class="active"><a data-toggle="tab" href="#popular">Popular</a></li>
                    <li><a data-toggle="tab" href="#recent">Recent</a></li>
                    <li><a data-toggle="tab" href="#commenticon"><img src="'.$theme_path.'/images/commenticon.png" alt="#"></a></li>
				</ul>
				<div class="tab-content">
                    <div id="popular" class="tab-pane fade in active">
                    	<div class="popularitem1">
							<h1>Real Hypnosis, Real Funny</h1>
							<h2>Friday, June 26, 2015</h2>
                          	<img src="'.$theme_path.'/images/hmblck1rghtsidetabimg1.png" alt="#">
                          	<h3><span>Lorem Ipsum</span> is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.</h3>
						</div>
                        
                        <input type="submit" class="viewmore" value="view more">
                    </div>
                    <div id="recent" class="tab-pane fade">
                       <div class="popularitem1">
							<h1>Real Hypnosis, Real Funny</h1>
							<h2>Friday, June 26, 2015</h2>
                          	<img src="'.$theme_path.'/images/hmblck1rghtsidetabimg1.png" alt="#">
                          	<h3><span>Lorem Ipsum</span> is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.</h3>
						</div>
                       
                        <input type="submit" class="viewmore" value="view more">
                    </div>
                    <div id="commenticon" class="tab-pane fade">
                      <div class="popularitem1">
							<h1>Real Hypnosis, Real Funny</h1>
							<h2>Friday, June 26, 2015</h2>
                          	<img src="'.$theme_path.'/images/hmblck1rghtsidetabimg1.png" alt="#">
                          	<h3><span>Lorem Ipsum</span> is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.</h3>
						</div>
                        
                        <input type="submit" class="viewmore" value="view more">
                    </div>
                  </div>
            </div>
            <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 hmblck3rhtsideblck3">
            	<img src="'.$theme_path.'/images/hmblck3rightsideblck3bg.png" alt="#" class="img-responsive">
				
            </div>
        </div>
    </div>
</div>';


    return $output;
}
