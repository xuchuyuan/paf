<?php

	class myClass {

		var $xmlContent = '';
		var $funcList   = [];

		function myClass($xmlname) {

			$filename = PAF_PATH.'/Library/Class/'.$xmlname.'.xml';
			$this->xmlContent = file_get_contents($filename);
			$this->loadXml();
		}

		function __call($funcName, $param) {
			if(array_key_exists($funcName, $this->funcList)) {
				$db  = load_db();
				$sql = $this->funcList[$funcName]['sql'];
				$param ? $sql = $this->pregParams($sql, $param) : '';
				switch ($this->funcList[$funcName]['resultType']) {
					case 'array' :
						return $db->execForArray($sql);
					case 'int' : 					
						return intval($db->execForOne($sql));
					case 'string' : 					
						return strval($db->execForOne($sql));
					default:
						# code...
						break;
				}
			}
		}

		function pregParams($sql, $param) {
			$index = 0;
			foreach ($param as $value) {
				$sql = str_replace('#{'.$index.'}', $value, $sql);
				$index++;
			}
			return $sql;
		} 

		function loadXml() {
			$conf = (array)simplexml_load_string($this->xmlContent);
			foreach ($conf['func'] as $value) {
				$this->funcList[strval($value->name)] = [
					'sql'         => strval($value->sql),
					'description' => strval($value->description),
					'resultType'  => strval($value->resultType),
				];
			}
		}

	}
?>