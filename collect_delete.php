<?php
include_once 'inc/config.inc.php';
include_once 'inc/mysql.inc.php';
include_once 'inc/tool.inc.php';
$link=connect();
if(!$member_id=is_login($link)){
    skip('login.php','error','请先登录');
}
if(!isset($_GET['id'])||!is_numeric($_GET['id'])){
    skip('index.php','error','id参数错误');
    exit();
}
$query="select member_id from collect where id={$_GET['id']}";
$result_content=execute($link,$query);
if(mysqli_num_rows($result_content)==1){
    $data_content=mysqli_fetch_assoc($result_content);
    if(check_user($member_id,$data_content['member_id'],$is_manage_login)){
        $query="delete from collect where id={$_GET['id']}";
        execute($link,$query);
        if(mysqli_affected_rows($link)==1){
            
            skip("member.php?id={$member_id}",'ok','恭喜你取消收藏成功');
            exit();
        }else{
            skip("member.php?id={$member_id}",'error','取消收藏失败');
            exit();
        }
    }else{
        skip('index.php','error','这个帖子不属于你');
        exit();
    }
}else{
    skip('index.php','error','帖子不存在');
    exit();
}
?>