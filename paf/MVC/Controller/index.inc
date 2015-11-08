<?php
	
	class index extends _Master {

		public function showindex() {

			//load smarty
			// include(PAF_PATH.'/MVC/View/'.PAF_VIEW_PATH.'/index.php');
			
			$this->setView('index'); 

			$this->setVar('title', 'title测试');	


			$md = load_model('UserModel');
			$md->user_id = 88;
			$md->user_name = 'xcy';
			$md->user_email = 'xcy@163.com';
			$md->user_pass = '';

			set_user($md, 60 * 60);
			if(is_login()) {
				$this->setVar('userState', '用户:'.the_user()->user_name);
			}else {
				$this->setVar('userState', '未登录');
			}


			$db  = load_db();
			$sql = 'select * from weibo limit 10'; 
			$this->setVar('weibolist', $db->execForArray($sql));

		}
	}
?>