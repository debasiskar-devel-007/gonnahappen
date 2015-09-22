<?php
/**
 * Implements hook_html_head_alter().
 * This will overwrite the default meta character type tag with HTML5 version.
 */
function professional_theme_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8'
  );
}

/**
 * Insert themed breadcrumb page navigation at top of the node content.
 */



//to manage form element wrapper and showing errors inline
function professional_theme_form_element($variables) {
    $output = '';



    $output = $variables['element']['#children'];
   // echo strlen($variables['element']['#name']);
    $elementname= substr($variables['element']['#name'],0,strlen($variables['element']['#name'])-1);
    $pos = strpos($elementname,'[');
    if ($pos !== false) {
         $elementname = substr_replace($elementname,'][',$pos,strlen('['));
    }
    //var_dump(form_get_errors());


    if(is_array(form_get_errors())){



        if (array_key_exists($variables['element']['#name'],form_get_errors()) || array_key_exists($elementname,form_get_errors())) {
            $errors=form_get_errors();
           // echo $variables['element']['#name'];
            if(!isset($errors[$variables['element']['#name']])) $errors[$variables['element']['#name']]=$errors[$elementname];
            $output .= '<div class="messages error messages-inline">' . @$errors[$variables['element']['#name']] . '</div>';
        }
    }
    return $output;


}
function professional_theme_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    // Use CSS to hide titile .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    // comment below line to hide current page to breadcrumb
	$breadcrumb[] = drupal_get_title();
    $output .= '<nav class="breadcrumb">' . implode(' » ', $breadcrumb) . '</nav>';
    return $output;
  }
}

/**
 * Override or insert variables into the page template.
 */
function professional_theme_preprocess_page(&$vars) {
  if (isset($vars['main_menu'])) {
    $vars['main_menu'] = theme('links__system_main_menu', array(
      'links' => $vars['main_menu'],
      'attributes' => array(
        'class' => array('links', 'main-menu', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  else {
    $vars['main_menu'] = FALSE;
  }
  if (isset($vars['secondary_menu'])) {
    $vars['secondary_menu'] = theme('links__system_secondary_menu', array(
      'links' => $vars['secondary_menu'],
      'attributes' => array(
        'class' => array('links', 'secondary-menu', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Secondary menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  else {
    $vars['secondary_menu'] = FALSE;
  }
  // Add javascript files for front-page jquery slideshow.
  if (drupal_is_front_page() || theme_get_setting('slideshow_all')) {
    $directory = drupal_get_path('theme', 'professional_theme');
    drupal_add_js($directory . '/js/jquery.flexslider-min.js', array('group' => JS_THEME));
    drupal_add_js($directory . '/js/slide.js', array('group' => JS_THEME));
  }
  // <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1"/>
  $viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' =>  'viewport',
      'content' =>  'width=device-width'
    )
  );
  drupal_add_html_head($viewport, 'viewport');
}

/**
 * Duplicate of theme_menu_local_tasks() but adds clearfix to tabs.
 */
function professional_theme_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs primary clearfix">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary clearfix">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }
  return $output;
}

/**
 * Override or insert variables into the node template.
 */
function professional_theme_preprocess_node(&$variables) {
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full' && node_is_page($variables['node'])) {
    $variables['classes_array'][] = 'node-full';
  }
}


