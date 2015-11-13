<?php
/**
 * @file
 * dashboard.theme.inc
 */

/**
 * Theme lawmaker full page.
 */
//print theme('links', array('links' => menu_navigation_links('menu-dashboard-menu'), 'attributes' => array('class'=> array('dashboard_link_list')) ));
function theme_dashboard($variables) {
  //$themepath=(drupal_get_path('theme',$GLOBALS['theme']));
    $themepath=(drupal_get_path('theme',$GLOBALS['theme']));

    $menu= menu_tree_all_data('menu-dashboard-menu');
   // var_dump($menu);
    $html='';
    if(count($menu>0))
    {
        foreach($menu as $key=>$val) {
            $link_path=$val["link"]["link_path"];
            $link_titile=$val["link"]["link_title"];
            $link_mlid=$val['link']['mlid'];
            $html .= '<li class="demo" >
    <a href="'.$link_path.'">
        <img mlid="'.$link_mlid.'" src="' . $themepath . '/images/d_icon2.png"><span class="demoss">'.

                $link_titile.
                '</span></a>
</li>';


        }    }

  $output = '

<div class="dashboard_wrapper">

  <div class="container-fluid">

    <div class="row">
    <div class="col-lg-8 col-md-12 col-xs-12 col-sm-12">

  <ul class="dashboard_link_list">'.$html.'




</ul>


</div>


     <div class="col-lg-4 col-md-12 col-xs-12 col-sm-12">
     <div class="acordian_block">

<div class="bs-example">
    <div class="panel-group" id="accordion">
        <div class="panel panel-default">
            <div class="panel-heading ">
                <h4 class="panel-title ">
                    <a  data-toggle="collapse" data-parent="#accordion" href="#collapseOne" > Last 5 Logged-in User</a>
                </h4>
            </div>
            <div id="collapseOne" class="panel-collapse collapse in">
                <div class="panel-body">
                  <table>
                   <tr>
                    <th> Name </th>
                    <th>Location </th>
                    <th>ID </th>
                    <th> Last Activity </th>
                    <th>Logout</th>
                   </tr>

                    <tr>
                     <td>Super User</td>
                     <td>Administrator</td>
                     <td>42</td>
                     <td>2012-11-21 20.14:30</td>
                     <td>&nbsp;</td>
                   </tr>

                    <tr>
                     <td>Super User</td>
                     <td>Administrator</td>
                     <td>42</td>
                     <td>2012-11-21 20.14:30</td>
                     <td>&nbsp;</td>
                   </tr>

                    <tr>
                     <td>Super User</td>
                     <td>Administrator</td>
                     <td>42</td>
                     <td>2012-11-21 20.14:30</td>
                     <td>&nbsp;</td>
                   </tr>


                </table>



                </div>
            </div>
        </div>
        <div class="panel panel-default">
            <div class="panel-heading ">
                <h4 class="panel-title">
                    <a data-toggle="collapse" data-parent="#accordion" href="#collapseTwo" > Top 5 Popular Articles</a>
                </h4>
            </div>
            <div id="collapseTwo" class="panel-collapse collapse">
                <div class="panel-body">
                    <p>Bootstrap is a powerful front-end framework for faster and easier web development. It is a collection of CSS and HTML conventions. <a href="http://www.tutorialrepublic.com/twitter-bootstrap-tutorial/" target="_blank">Learn more.</a></p>

                     <p>Bootstrap is a powerful front-end framework for faster and easier web development. It is a collection of CSS and HTML conventions. <a href="http://www.tutorialrepublic.com/twitter-bootstrap-tutorial/" target="_blank">Learn more.</a></p>
                </div>
            </div>
        </div>
        <div class="panel panel-default">
            <div class="panel-heading ">
                <h4 class="panel-title">
                    <a data-toggle="collapse" data-parent="#accordion" href="#collapseThree"> Last 5 Added Articles</a>
                </h4>
            </div>
            <div id="collapseThree" class="panel-collapse collapse">
                <div class="panel-body">
                    <p>CSS stands for Cascading Style Sheet. CSS allows you to specify various style properties for a given HTML element such as colors, backgrounds, fonts etc. <a href="http://www.tutorialrepublic.com/css-tutorial/" target="_blank">Learn more.</a></p>
                </div>
            </div>
        </div>
    </div>
</div>






     </div>

     </div>


</div>

</div>



</div>';


  return $output;
}
