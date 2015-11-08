<?php
	
	require('paf.conf');

	$_controller = isset($_GET['controller']) ? $_GET['controller'] : '';
	
	$_action     = isset($_GET['action']) ? $_GET['action'] : '';

	if($_controller == '' || in_array($_controller, explode(',', PAF_FORBIDDEN_TYPE))) {
		exit();
	}

	require(PAF_PATH.'/Common/functions.inc');

	require(PAF_PATH.'/MVC/controller/_Master.inc');


	$_controller_path = PAF_PATH.'/MVC/controller/'.$_controller.'.inc';
	
	if(!file_exists($_controller_path)) {
		exit();
	}

	require($_controller_path);

	if(!class_exists($_controller)) {
		exit();
	}

	$_init_controller = new $_controller();
	if(!method_exists($_init_controller, $_action)) {
		exit();
	}

	$_init_controller->$_action();
	$_init_controller->run();
	
?>