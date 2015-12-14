<?php
/**
 * @file
 * dashboard.theme.inc
 */

/**
 * Theme frontend full page.
 */



function theme_epartner_signup($variables) {


   global  $user;

    $theme_path=drupal_get_path('theme', 'frontendtheme');

    global $base_url;
    $old_revision = entity_load_single('banner',  24);
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
        $hometopeditimgpath = l($hometopeditimgpath, 'managebanner/24/event-partner-sign-up', array('html' => true));
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

    $poprecenthtml = '';
    if (module_exists('eventlist')) {
        $poprecenthtml = get_pop_recent_event();
    }
    $eventpartnersignuprightbannerhtml1 = '';
    $eventpartnersignuprightbannerhtml2 = '';
    if (module_exists('banner')) {
        $eventpartnersignuprightbannerhtml1 = right_dynamic_banner(45,'event-partner-sign-up');
        $eventpartnersignuprightbannerhtml2 = right_dynamic_banner(46,'event-partner-sign-up');
    }

    $output =  '
<div class="container-fluid banner-wrapper">

	<div class="row">'

        .$hometopeditimgpath.'

<div id="myCarousel" class="carousel slide" data-ride="carousel"
    <!-- Indicators -->


    <!-- Wrapper for slides -->
    <div class="carousel-inner" role="listbox">'.$img_listing.'</div>

    <!-- Left and right controls -->

  </div>


    </div>

</div>


<div class="container signuppage">
	<div class="row">
    	<div class="col-lg-8  col-lg-offset-0 col-md-10 col-md-offset-1 col-sm-12 col-sm-offset-0 col-xs-12 col-xs-offset-0">

           <div class="signupblock" >
		   <h2>Join us an <span>Event Partner</span> for a <br/>profitable journey

</h2>
		   
		   
           '.drupal_render(drupal_get_form('event_partner_sign_up_form')).'
           </div>

    	</div>

        <div class="col-lg-4 col-lg-offset-0 col-md-6 col-md-offset-3 col-sm-8 col-sm-offset-2 col-xs-10 col-xs-offset-1 hmblck3rhtside">
        	'.drupal_render(drupal_get_form('event_search')).'
        	<div style="font-size:12px;">*Search by Event Name,Event Category, Location or Tag List</div>
        	       	<div class="right_bannerad">'.$eventpartnersignuprightbannerhtml1.'</div>

        	<!--<h1>AD space</h1>-->
        	<div class="clearfix"></div>
            <!--<div class="col-lg-12 col-md-12 col-sm-12 ol-xs-12 hmblck3rhtsideblck1">
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
            </div>-->
            '.$poprecenthtml.'
            <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 hmblck3rhtsideblck3">
            '.$eventpartnersignuprightbannerhtml2.'
            	<!--<img src="'.$base_url.'/'.$theme_path.'/images/hmblck3rightsideblck3bg.png" alt="#" class="img-responsive">-->
            </div>
        </div>
    </div>
</div>';


    return $output;
}
