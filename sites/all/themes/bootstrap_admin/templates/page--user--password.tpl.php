<div class="login-box">
    <div class="login-logo">
        <a href="<?php echo $GLOBALS['base_url']; ?>"><img src="<?php echo $logo; ?>" /></a>
    </div><!-- /.login-logo -->
    <div class="login-box-body">
        <p class="login-box-msg">Forgot Your Password ?</p>


        <?php
        // print $messages;


        $elements = drupal_get_form("user_pass");
        $form = drupal_render($elements);
        echo $form;
        ?>









       <!-- <a href="#">I forgot my password</a><br>
        <a href="register.html" class="text-center">Register a new membership</a>-->

    </div><!-- /.login-box-body -->
</div>
