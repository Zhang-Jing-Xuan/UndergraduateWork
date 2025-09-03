<?php
if(empty($_POST['module_id'])|| !is_numeric($_POST['module_id'])){
    skip('publish.php','error','所属板块id错误');
    exit();
}
$query="select * from son_module where id={$_POST['module_id']}";
$result=execute($link,$query);
if(mysqli_num_rows($result)!=1){
    skip('publish.php','error','所属板块不存在');
    exit();
}
if(empty($_POST['title'])){
    skip('publish.php','error','标题不得为空');
    exit();
}
if(mb_strlen($_POST['title'])>255){
    skip('publish.php','error','标题不得超过255个字符');
    exit();
}
// escape($link,$_POST);
// $query="select * from member where name='{$_POST['time']}' and pw=md5('{$_POST['pw']}')";
?>