<?php
/**
 * @file
 * dashboard.theme.inc
 */

/**
 * Theme frontend full page.
 */



function theme_product_affiliate_list($variables) {
	global  $user;

    $theme_path=drupal_get_path('theme', 'frontendtheme');

    global $base_url;

	$output = '<div class="container-fluid banner-wrapper"><div class="row"><div class="col-lg-12  col-lg-offset-0 col-md-12 col-md-offset-0 col-sm-12 col-sm-offset-0 col-xs-12 col-xs-offset-0 eventbnnr-wrapper"><img src="'.$base_url.'/'.$theme_path.'/images/myaccountbanner.png" alt="#"></div></div></div>


<div class="container accountblock">
	<div class="row">
    	<div class="col-lg-12  col-lg-offset-0 col-md-12 col-md-offset-0 col-sm-12 col-sm-offset-0 col-xs-12 col-xs-offset-0 accountcontainer">


		<div class="container">

			<div class="row">

		<div class="col-lg-3  col-lg-offset-0 col-md-4 col-md-offset-0 col-sm-12 col-sm-offset-0 col-xs-12 col-xs-offset-0 left_menupart">
		<h2>User Account</h2>

		'.left_menu_manage().'


		</div>


        <div class="col-lg-9  col-lg-offset-0 col-md-8 col-md-offset-0 col-sm-12 col-sm-offset-0 col-xs-12 col-xs-offset-0 rightmainblock">

         <h6 class="pageheading">Product Affiliate List</h6>
<div class="addeventpage">
		'.productaffiliatelistcontent().'
		</div>
		</div>


        </div>

	</div>


    	</div>


    </div>
</div>';


    return $output;
}
