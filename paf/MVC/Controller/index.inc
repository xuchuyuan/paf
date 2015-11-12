<?php
	
	class index extends _Master {

		public function showindex() {
			
			$this->setView('index'); 

			/*
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
			*/
			
			/*
			$user = load_model('WeiboModel');
			$user->_view_name = 'weibo';
			$user->_id_key    = 'uid';
			$user->_id 		  = '1157864602';
			
			$user->load();
			$this->setVar('UserModel', $user);
			*/
			
			/*
			*	$db    = load_db();
			*	$sql[] = "insert into user(uname, area) values ('Yuen_Hsu', '上海，杨浦区')";
			*	$sql[] = "select LAST_INSERT_ID() into @userid";
			*	$sql[] = "insert into user_detail(uid, realname, userqq) values (@userid, '许楚原', '549362932')";
			*	$sql[] = "select @userid";
			*	
			*	$userid = $db->execForTrac($sql, 'int');
			*	exit('用户id为:'.$userid);
			*/
			
			/*
			$news = load_class('news');
			$return = $news->getUserDetail('1075866671', '徐兆寿');
			*/
			
			$return = $this->news->getUserDetail('1075866671', '徐兆寿');
			var_export($return);
			exit();

		}
	}
?>