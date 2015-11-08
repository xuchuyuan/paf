<?php
	
	function test() {
		echo "testInc";
	}

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
