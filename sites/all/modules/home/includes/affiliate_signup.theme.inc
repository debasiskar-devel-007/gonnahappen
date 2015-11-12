<?php
/**
 * @file
 * dashboard.theme.inc
 */

/**
 * Theme frontend full page.
 */



function theme_affiliate_signup($variables) {
   global  $user;

    $theme_path=drupal_get_path('theme', 'frontendtheme');

    global $base_url;


    $poprecenthtml = '';
    if (module_exists('eventlist')) {
        $poprecenthtml = get_pop_recent_event();
    }

    $output = '<div class="container-fluid banner-wrapper"><div class="row"><div class="col-lg-12  col-lg-offset-0 col-md-12 col-md-offset-0 col-sm-12 col-sm-offset-0 col-xs-12 col-xs-offset-0 eventbnnr-wrapper"><img src="'.$base_url.'/'.$theme_path.'/images/free_eventbanner.png" alt="#"></div></div></div>


<div class="container signuppage">
	<div class="row">
    	<div class="col-lg-8  col-lg-offset-0 col-md-10 col-md-offset-1 col-sm-12 col-sm-offset-0 col-xs-12 col-xs-offset-0">

           <div class="signupblock" >
		   <h2>Get your own <span>gonnahappen.com<span> </br>
account in seconds </h2>
		   
		   
           '.drupal_render(drupal_get_form('general_user_sign_up_form')).'
           </div>

    	</div>

        <div class="col-lg-4 col-lg-offset-0 col-md-6 col-md-offset-3 col-sm-8 col-sm-offset-2 col-xs-10 col-xs-offset-1 hmblck3rhtside">
        	'.drupal_render(drupal_get_form('event_search')).'
        	<div style="font-size:12px;">*Search by Event Name,Event Category, Location or Tag List</div>
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
            '.$poprecenthtml.'
            <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 hmblck3rhtsideblck3">
            	<img src="'.$base_url.'/'.$theme_path.'/images/hmblck3rightsideblck3bg.png" alt="#" class="img-responsive">
            </div>
        </div>
    </div>
</div>';


    return $output;
}
