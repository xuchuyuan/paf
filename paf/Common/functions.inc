<?php

	function is_login() {
		if(the_user()) {
			return true;
		}

		return false;
	}

	function the_user() {

		return isset($_COOKIE[PAF_USER_COOKIE]) ? json_decode($_COOKIE[PAF_USER_COOKIE]) : false;

	}

	function set_user($md, $time) {
		if($time <= 0) {
			//注销user
			setcookie(PAF_USER_COOKIE, '', time() - 60*60, '/');
		}else {
			setcookie(PAF_USER_COOKIE, json_encode($md), time() + $time, '/');
		}
	}

	/**
	 * 加载model
	 * @return [type]            [description]
	 */
	function load_model($modelName) {

		$_ModelPath = PAF_PATH.'/MVC/Model/_Model.inc';
		if(!class_exists($_ModelPath)) {
			require($_ModelPath);
		}

		$mdPath = PAF_PATH.'/MVC/MODEL/'.$modelName.'.inc';
		if(file_exists($mdPath)) {
			require_once(PAF_PATH.'/MVC/MODEL/'.$modelName.'.inc');	
		}

		return new $modelName();
		
	}


	function load_db() {
		$dbPath = PAF_PATH.'/Library/DataBase/myDataBase.php';
		if(!class_exists($dbPath)) {
			require($dbPath);			
		}
		return new myDataBase();
	}
	

	//加载虚拟类,解析xml
	function load_class($xmlname) {
		$classPath = PAF_PATH.'/Library/Class/myClass.php';
		if(!class_exists($classPath)) {
			require($classPath);			
		}
		return new myClass($xmlname);
	}
