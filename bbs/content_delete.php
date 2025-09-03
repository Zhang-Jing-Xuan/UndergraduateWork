<?php
include_once 'inc/config.inc.php';
include_once 'inc/mysql.inc.php';
include_once 'inc/tool.inc.php';
$link=connect();
$is_manage_login=is_manage_login($link);
$member_id=is_login($link);
if(!$member_id&&!$is_manage_login){
    skip('login.php','error','请先登录');
}
if(!isset($_GET['id'])||!is_numeric($_GET['id'])){
    skip('index.php','error','id参数错误');
    exit();
}
$query="select member_id from content where id={$_GET['id']}";
$result_content=execute($link,$query);
if(mysqli_num_rows($result_content)==1){
    $data_content=mysqli_fetch_assoc($result_content);
    if(check_user($member_id,$data_content['member_id'],$is_manage_login)){
        $query="delete from content where id={$_GET['id']}";
        execute($link,$query);
        if(isset($_GET['return_url'])){
            $return_url=$_GET['return_url'];
        }else{
            $return_url="member.php?id={$member_id}";
        }
        if(mysqli_affected_rows($link)==1){
            skip($return_url,'ok','删除成功！');
            exit();
        }else{
            skip($return_url,'error','删除失败，请重试！');
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