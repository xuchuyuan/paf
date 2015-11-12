<?php
	
	require('adodb.inc.php');

	class myDataBase {

		public $_dbAddr = 'localhost';
		public $_dbName = 'crawl_data';
		public $_dbUser = 'root';
		public $_dbPwd  = '123456';

		public $_db = false;

		function myDataBase() {
			$this->initConnect();
		}

		function __destruct() {
			if($this->_db && $this->_db->IsConnected()) {
				$this->_db->disconnect();
				unset($this->_db);
			}
		}

		function initConnect() {
			$this->_db = NewADOConnection('mysqli');
			$this->_db->Connect($this->_dbAddr, $this->_dbUser, $this->_dbPwd, $this->_dbName);
			$this->_db->Query('set names utf8');
			$this->_db->SetFetchMode(ADODB_FETCH_ASSOC);
		}

		function execForNothing($sql) {
			$this->_db->Execute($sql);
		}

		function execForArray ($sql) {
			$result = $this->_db->Execute($sql);	
			if($result) {
				$returnArray = [];
				while(!$result->EOF) {
					$returnArray[] = $result->fields;
					$result->MoveNext();
				}
				return $returnArray;
			}else {
				return false;
			}
		}

		function execForOne ($sql) {
			return  $this->_db->GetOne($sql);
		}

		//事务
		function execForTrac($sqllist, $returntype) {
			$type = ['none', 'string', 'array', 'int'];
			if(!in_array($returntype, $type)) {
				return false;
			}

			if(0 == count($sqllist)) {
				return false;
			}

			//开启事务
			$this->_db->BeginTrans();
			$sqlindex = 0;
			$ret = true;

			foreach ($sqllist as $sql) {
				if($sqlindex == (count($sqllist)-1)) {
					if($returntype == 'none') {
						$this->_db->Execute($sql);
					}else if($returntype == 'array') {
						$ret = $this->execForArray($sql);
					}else if($returntype == 'int' || $returntype == 'string') {
						$ret = $this->execForOne($sql);
					}else {
						$ret = $this->execForArray($sql);
					}
				}else {
					$this->_db->Execute($sql);
				}

				$sqlindex++;
			}

			if($ret) {
				$this->_db->CommitTrans();
			}else {
				$this->_db->RollbackTrans();
			}

			return $ret;
		}
	}
?>	