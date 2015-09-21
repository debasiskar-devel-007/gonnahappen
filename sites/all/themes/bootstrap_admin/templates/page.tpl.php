<div class="wrapper">






    <?php
    $themepath=(drupal_get_path('theme',$GLOBALS['theme']));





    ?>


    <header class="main-header">


        <!-- Logo -->
        <a href="index2.html" class="logo">
            <!-- mini logo for sidebar mini 50x50 pixels -->
          <!--  <span class="logo-mini"><b>A</b>LT</span>-->
            <!-- logo for regular state and mobile devices -->

                <?php if ($logo): ?>
            <span class="logo-lg">

                  <img src="sites/all/themes/bootstrap_admin/img/logo.png"  >

                </span>
                <?php endif; ?>
                <!--<b>Admin</b>LTE-->

        </a>

        <!-- Header Navbar -->
        <nav class="navbar navbar-static-top" role="navigation">
            <!-- Sidebar toggle button-->
            <a href="#" class="sidebar-toggle" data-toggle="offcanvas" role="button">
                <span class="sr-only">Toggle navigation</span>
            </a>
            <!-- Navbar Right Menu -->
            

            <div class="navbar-custom-menu">
                <ul class="nav navbar-nav">
                
                            <li class="searvhbox">
                            
                             <form action="#" method="get" class="sidebar-form">
                <div class="input-group">
                    <input type="text" name="q" class="form-control" placeholder="Search...">
              <span class="input-group-btn">
                <button type="submit" name="search" id="search-btn" class="btn btn-flat"><i class="fa fa-search"></i></button>
              </span>
                </div>
            </form>

</li>
        
                    <li class="dropdown user user-menu">
                        <!-- Menu Toggle Button -->
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">
                            <!-- The user image in the navbar-->
                            <img src="<?php echo $themepath ; ?>/img/user2-160x160.jpg" class="user-image" alt="User Image">
                            <!-- hidden-xs hides the username on small devices so only the image appears. -->
                            <span class="hidden-xs">
                            <strong>Alexander Pierce</strong>

                            <label>Administrator</label>
                            
                            </span>
                            
                            <div style="clear:both;"></div>
                        </a>
                        <ul class="dropdown-menu">
                            <!-- The user image in the menu -->
                            <li class="user-header">
                                <img src="<?php echo $themepath ; ?>/img/user2-160x160.jpg" class="img-circle" alt="User Image">
                                <p>
                                    Alexander Pierce - Web Developer
                                    <small>Member since Nov. 2012</small>
                                </p>
                            </li>
                            <!-- Menu Body -->
                            <li class="user-body">
                                <div class="col-xs-4 text-center">
                                    <a href="#">Followers</a>
                                </div>
                                <div class="col-xs-4 text-center">
                                    <a href="#">Sales</a>
                                </div>
                                <div class="col-xs-4 text-center">
                                    <a href="#">Friends</a>
                                </div>
                            </li>
                            <!-- Menu Footer-->
                            <li class="user-footer">
                                <div class="pull-left">
                                    <a href="#" class="btn btn-default btn-flat">Profile</a>
                                </div>
                                <div class="pull-right">
                                    <a href="#" class="btn btn-default btn-flat">Sign out</a>
                                </div>
                            </li>
                        </ul>
                    </li>
                    <!-- Control Sidebar Toggle Button -->
                 
                </ul>
            </div>
        </nav>
        
        
        <div class="header_bottom">
        
        <h2>Events Manager</h2>
        <nav class="navbar navbar-default toprightmenu" >

    
   
      <ul class="nav navbar-nav">
        <li class="active"><a href="#">Dashboard</a></li>
        <li><a href="#">Homepage</a></li>
        <li><a href="#">Orders</a></li>
        <li><a href="#">Users</a></li>
        <li><a href="#">Menus</a></li>
         <li><a href="#">Help</a></li>
      </ul>
   

</nav>

<div style="clear:both;"></div>
        
        </div>
        
        
        
    </header>
    
    
 


    <aside class="main-sidebar">

        <!-- sidebar: style can be found in sidebar.less -->
        <section class="sidebar">





            <ul class="sidebar-menu  left_side_menu">
              
                <!-- Optionally, you can add icons to the links -->
                <li class="active"><a href="#"> <img src="sites/all/themes/bootstrap_admin/img/nav1.png"  alt="#"/> Banner Manager</a></li>
                <li><a href="#"><img src="sites/all/themes/bootstrap_admin/img/nav2.png"  alt="#"/>Events Manager</a></li>
                <li><a href="#">  <img src="sites/all/themes/bootstrap_admin/img/nav3.png"  alt="#"/> Tournament Manager</a></li>
                <li><a href="#">  <img src="sites/all/themes/bootstrap_admin/img/nav4.png"  alt="#"/>  Artist Manager</a></li>
                <li><a href="#">  <img src="sites/all/themes/bootstrap_admin/img/nav5.png"  alt="#"/>  User Manager</a></li>
                <li><a href="#"> <img src="sites/all/themes/bootstrap_admin/img/nav6.png"  alt="#"/>  Affiliate Manager</a></li>
                <li><a href="#">   <img src="sites/all/themes/bootstrap_admin/img/nav7.png"  alt="#"/> Ads Manager</a></li>
                <li><a href="#"> <img src="sites/all/themes/bootstrap_admin/img/nav8.png"  alt="#"/>  Contact Manager</a></li>
                <li><a href="#"> <img src="sites/all/themes/bootstrap_admin/img/nav9.png"  alt="#"/>  Talent Manager</a></li>
               <li><a href="#"> <img src="sites/all/themes/bootstrap_admin/img/nav10.png"  alt="#"/>  Auto Email Manager</a></li>
               <li><a href="#">  <img src="sites/all/themes/bootstrap_admin/img/nav11.png"  alt="#"/>  Media</a></li>
               <li><a href="#">  <img src="sites/all/themes/bootstrap_admin/img/nav12.png"  alt="#"/>  Comments</a></li>
              <li><a href="#">  <img src="sites/all/themes/bootstrap_admin/img/nav13.png"  alt="#"/> Products</a></li>
             <li><a href="#">  <img src="sites/all/themes/bootstrap_admin/img/nav14.png"  alt="#"/>  FAQ</a></li>
            <li><a href="#">   <img src="sites/all/themes/bootstrap_admin/img/nav15.png"  alt="#"/> News Blog</a></li>
    <li><a href="#">   <img src="sites/all/themes/bootstrap_admin/img/nav16.png"  alt="#"/> Terms and Condition</a></li>
<li><a href="#">  <img src="sites/all/themes/bootstrap_admin/img/nav17.png"  alt="#"/>  Privacy Statement</a></li>
<li><a href="#">  <img src="sites/all/themes/bootstrap_admin/img/nav18.png"  alt="#"/>  Return and Shipping Policy</a></li>
 <li><a href="#">  <img src="sites/all/themes/bootstrap_admin/img/nav19.png"  alt="#"/>  Affiliate Agreement</a></li>

                
                
                
                
                
                
                
      
                <!--<li class="treeview">
                    <a href="#"><i class="fa fa-link"></i> <span>Multilevel</span> <i class="fa fa-angle-left pull-right"></i></a>
                    <ul class="treeview-menu">
                        <li><a href="#">Link in level 2</a></li>
                        <li><a href="#">Link in level 2</a></li>
                    </ul>
                </li>-->
            </ul><!-- /.sidebar-menu -->
        </section>
        <!-- /.sidebar -->
    </aside>










<div class="content-wrapper">
    <!-- Content Header (Page header) -->
    <section class="content-header">
        <h1>
            Page Header
            <small>Optional description</small>
        </h1>
        <ol class="breadcrumb">
            <li><a href="#"><i class="fa fa-dashboard"></i> Level</a></li>
            <li class="active">Here</li>
        </ol>
    </section>

    <!-- Main content -->
    <section class="content">

        <!-- Your Page Content Here -->

<?php

print render($page['content']); ?>

    </section><!-- /.content -->
</div>








<footer class="main-footer">
    <!-- Default to the left -->
    <div class="footer_text">&copy; 2015 <a href="#">gonnahappen</a>.All rights reserved.</div>
    
    <img src="sites/all/themes/bootstrap_admin/img/footerlogo.png"  alt="#"/>
    <div style="clear:both;"></div>
    
</footer>
 
<!-- Control Sidebar -->
<aside class="control-sidebar control-sidebar-dark">
    <!-- Create the tabs -->
    <ul class="nav nav-tabs nav-justified control-sidebar-tabs">
        <li class="active"><a href="#control-sidebar-home-tab" data-toggle="tab"><i class="fa fa-home"></i></a></li>
        <li><a href="#control-sidebar-settings-tab" data-toggle="tab"><i class="fa fa-gears"></i></a></li>
    </ul>
    <!-- Tab panes -->
    <div class="tab-content">
        <!-- Home tab content -->
        <div class="tab-pane active" id="control-sidebar-home-tab">
            <h3 class="control-sidebar-heading">Recent Activity</h3>
            <ul class="control-sidebar-menu">
                <li>
                    <a href="javascript::;">
                        <i class="menu-icon fa fa-birthday-cake bg-red"></i>
                        <div class="menu-info">
                            <h4 class="control-sidebar-subheading">Langdon's Birthday</h4>
                            <p>Will be 23 on April 24th</p>
                        </div>
                    </a>
                </li>
            </ul><!-- /.control-sidebar-menu -->

            <h3 class="control-sidebar-heading">Tasks Progress</h3>
            <ul class="control-sidebar-menu">
                <li>
                    <a href="javascript::;">
                        <h4 class="control-sidebar-subheading">
                            Custom Template Design
                            <span class="label label-danger pull-right">70%</span>
                        </h4>
                        <div class="progress progress-xxs">
                            <div class="progress-bar progress-bar-danger" style="width: 70%"></div>
                        </div>
                    </a>
                </li>
            </ul><!-- /.control-sidebar-menu -->

        </div><!-- /.tab-pane -->
        <!-- Stats tab content -->
        <div class="tab-pane" id="control-sidebar-stats-tab">Stats Tab Content</div><!-- /.tab-pane -->
        <!-- Settings tab content -->
        <div class="tab-pane" id="control-sidebar-settings-tab">
            <form method="post">
                <h3 class="control-sidebar-heading">General Settings</h3>
                <div class="form-group">
                    <label class="control-sidebar-subheading">
                        Report panel usage
                        <input type="checkbox" class="pull-right" checked>
                    </label>
                    <p>
                        Some information about this general settings option
                    </p>
                </div><!-- /.form-group -->
            </form>
        </div><!-- /.tab-pane -->
    </div>
</aside><!-- /.control-sidebar -->
<!-- Add the sidebar's background. This div must be placed
     immediately after the control sidebar -->
<div class="control-sidebar-bg"></div>



</div>

