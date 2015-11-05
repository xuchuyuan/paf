<?php
	
	include('paf.conf');

	include(PAF_PATH.'/MVC/View/'.PAF_VIEW_PATH.'/index.php');

	$_controller = isset($_GET['controller']) ? $_GET['controller'] : '';
	
	$_action     = isset($_GET['action']) ? $_GET['action'] : '';

	// var_dump( explode(',', PAF_FORBIDDEN_TYPE));

	if($_controller == '' || in_array($_controller, explode(',', PAF_FORBIDDEN_TYPE))) {
		exit();
	}

	include(PAF_PATH.'Common/functions.inc');
		
?>