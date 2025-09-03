<?php
if(mb_strlen($_POST['content'])<3){
    skip($_SERVER['REQUEST_URI'],'error','回复内容不得少于3个字');
    exit();
}
// escape($link,$_POST);
// $query="select * from member where name='{$_POST['time']}' and pw=md5('{$_POST['pw']}')";
?>