<?php

function bootstrap_admin_form_element($variables) {

	//var_dump($variables);


    $output = '';



    $output = $variables['element']['#children'];
    //var_dump($variables["element"]);


    if($variables["element"]['#title']=='Username'){
        $output = " <div class='form-group has-feedback'>".$output."
        <span class='glyphicon glyphicon-user form-control-feedback'></span>
              </div>";

    }
    elseif($variables["element"]['#title']=='Password'){
        $output = " <div class='form-group has-feedback'>".$output."
         <span class='glyphicon glyphicon-lock form-control-feedback'></span>
              </div>";

    }
    elseif($variables["element"]['#title']=='rememberme'){
        //echo 35;
        $output = '<div class="row">
                  <div class="col-xs-8">
                      <div class="checkbox icheck">
                          <label class="">
                              <div class="icheckbox_square-blue" aria-checked="false" aria-disabled="false" style="position: relative;">'.$output.

            ' <ins class="iCheck-helper" style="position: absolute; top: -20%; left: -20%; display: block; width: 140%; height: 140%; margin: 0px; padding:
   0px; border: 0px; opacity: 0; background: rgb(255, 255, 255);"></ins></div> Remember Me
                          </label>
                      </div>
                  </div></div></div>';

    }

	else{

		if($variables['element']['#type']!='checkbox')

    $output = '<div class="form-group">
			<label for="exampleInputEmail1">'.$variables['element']['#title'].'</label>
	'.$variables['element']['#children'].' <div>'.@$variables['element']['#description'].'</div></div>';

	if($variables['element']['#type']=='checkbox')

	 $output = '<div class="checkbox">
			<label >'.$variables['element']['#children']. $variables['element']['#title'].'</label>


			</div>';

	}

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



	function bootstrap_admin_form_elementff($variables) {

		$output = '';


		if($variables['element']['#type']!='checkbox')

    $output = '<div class="form-group">
			<label for="exampleInputEmail1">'.$variables['element']['#title'].'</label>
	'.$variables['element']['#children'].' <div>'.$variables['element']['#description'].'</div></div>';

	if($variables['element']['#type']=='checkbox')

	 $output = '<div class="checkbox">
			<label >'.$variables['element']['#children']. $variables['element']['#title'].'</label>


			</div>';

	 if(is_array(form_get_errors())){



        if (array_key_exists($variables['element']['#name'],form_get_errors()) || array_key_exists($elementname,form_get_errors())) {
            $errors=form_get_errors();
            // echo $variables['element']['#name'];
            if(!isset($errors[$variables['element']['#name']])) $errors[$variables['element']['#name']]=$errors[$elementname];
            $output .= '<div class="messages error messages-inline">' . @$errors[$variables['element']['#name']] . '</div>';
        }
    }

		//var_dump($variables);

		return $output;
	}


function bootstrap_admin_preprocess_table(&$variables) {


  $variables['attributes']['class'] = array('table', 'table-bordered', 'table-hover', 'dataTable');
}




?>