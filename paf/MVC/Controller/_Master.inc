<?php
	
	/*
	 *全局controller
	 */
	abstract class _Master {

		var $_view;

		var $_vars = [];


		function setView($viewName) {
			
			$this->_view = $viewName;

		}

		function getView() {

			return PAF_PATH.'/MVC/View/'.PAF_VIEW_PATH.'/'.$this->_view.PAF_VIEW_EXT;

		}

		function __get($var) {
			
			return load_class($var);
		}

		function setVar($name, $value) {

			$this->_vars[$name] = $value;

		}

		function run() {

			//解包
			extract($this->_vars);

			//加载头部
			include(PAF_PATH.'/MVC/View/'.PAF_VIEW_PATH.'/'.PAF_VIEW_HEADER.PAF_VIEW_EXT);

			//加载模板
			include($this->getView());

			//加载尾部
			include(PAF_PATH.'/MVC/View/'.PAF_VIEW_PATH.'/'.PAF_VIEW_FOOTER.PAF_VIEW_EXT);
		}
	}

?>