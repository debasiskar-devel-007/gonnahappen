<div class="login-box">
    <div class="login-logo">
        <a href="<?php echo $GLOBALS['base_url']; ?>"><img src="<?php echo $logo; ?>" /></a>
    </div><!-- /.login-logo -->
    <div class="login-box-body">
        <p class="login-box-msg">Sign in to start your session</p>


        <?php
        // print $messages;

        global $base_url;
        $elements = drupal_get_form("user_login");
        $form = drupal_render($elements);
        echo $form;
        ?>









        <a href="<?php echo $base_url?>/user/password">I forgot my password</a><br>
        <!--<a href="register.html" class="text-center">Register a new membership</a>-->

    </div><!-- /.login-box-body -->
</div>
