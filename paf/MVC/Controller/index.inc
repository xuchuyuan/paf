<?php
	
	class index extends _Master {

		public function showindex() {
			
			$this->setView('index'); 

			/**
			*	$md = load_model('UserModel');
			*	$md->user_id = 88;
			*	$md->user_name = 'xcy';
			*	$md->user_email = 'xcy@163.com';
			*	$md->user_pass = '';
			*
			*	set_user($md, 60 * 60);
			*	if(is_login()) {
			*		$this->setVar('userState', '用户:'.the_user()->user_name);
			*	}else {
			*		$this->setVar('userState', '未登录');
			*	}
			**/
		
			$user = load_model('WeiboModel');
			
			$user->_view_name = 'weibo';
			$user->_id 		  = '1075866671';
			
			$user->load();
			$this->setVar('UserModel', $user);

		}
	}
?>