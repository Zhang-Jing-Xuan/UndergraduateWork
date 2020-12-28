<?php
include_once 'inc/config.inc.php';
include_once 'inc/mysql.inc.php';
include_once 'inc/tool.inc.php';
$link=connect();
$member_id=is_login($link);
if(!$member_id){
	skip("index.php",'error','您没有登录，不需要退出');
	exit();
}
setcookie('zjx[name]','',time()-3600);
setcookie('zjx[pw]','',time()-3600);
skip("index.php",'ok','退出成功！');
exit();
$template['title']='会员登录页';
$template['css']=array('style/public.css','style/register.css');
?>