<?php
include_once 'inc/config.inc.php';
include_once 'inc/mysql.inc.php';
include_once 'inc/tool.inc.php';
$link=connect();
if(!$member_id=is_login($link)){
    skip('login.php','error','请登录之后再收藏');
    exit();
}
if(!isset($_GET['id'])||!is_numeric($_GET['id'])){
    skip('login.php','error','id参数错误');
    exit();
}
$query="select member_id from content where id={$_GET['id']}";
$result_collect=execute($link,$query);
if(mysqli_num_rows($result_collect)!=1){
    skip('show.php','error','不存在您要收藏的帖子');
    exit();
}else{
    $query="select count(*) from collect where content_id={$_GET['id']} and member_id={$member_id}";
    $cnt=num($link,$query);
    if($cnt!=0){
        skip('show.php','error','该帖子已经被您收藏');
        exit();
    }
    $query="insert into collect(content_id,time,member_id)values({$_GET['id']},now(),{$member_id})";
    execute($link,$query);
    if(mysqli_affected_rows($link)==1){
        skip("show.php?id={$_GET['id']}",'ok','收藏成功！');
        exit();
    }else{
        skip($_SERVER['REQUEST_URI'],'error','收藏失败，请重试！');
        exit();
    }
}
?>