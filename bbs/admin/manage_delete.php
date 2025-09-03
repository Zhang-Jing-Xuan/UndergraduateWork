<?php
	include_once '../inc/config.inc.php';
	include_once '../inc/mysql.inc.php';
	include_once '../inc/tool.inc.php';
	$link=connect();
	include_once 'inc/is_manage_login.inc.php';
	if(!is_manage_login($link)){
        skip('login.php','error','请先登录');
        exit();
	}
	if(basename($_SERVER['SCRIPT_NAME'])=='manage_delete.php'||basename($_SERVER['SCRIPT_NAME'])=='manage_add.php'){
		if($_SESSION['manage']['level']!='0'){
			if(!isset($_SERVER['HTTP_REFERER'])){
				$_SERVER['HTTP_REFERER']='index.php';
			}
			skip($_SERVER['HTTP_REFERER'],'error','对不起，您不是超级管理员,无法删除其他管理员');
			exit();
		}
	}
	if(!isset($_GET['id'])||!is_numeric($_GET['id'])){
		skip('manage.php',"error","id参数错误");
	}
	$query="delete from manage where id={$_GET['id']}";
	//echo($query);exit();
	execute($link,$query);
	if(mysqli_affected_rows($link)==1){
		skip('manage.php',"ok","恭喜你删除成功！");
	}else{
		skip('manage.php',"error","对不起，删除失败！请重试！");
	}
	
?>