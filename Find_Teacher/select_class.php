<?php
    include_once 'inc/config.inc.php';
    include_once 'inc/mysql.inc.php';
    include_once 'inc/tool.inc.php';
    include_once 'inc/page.inc.php';
    $link=connect();
    $member_id=is_login($link);
    if(!$member_id=is_login($link)){
        skip('login.php','error','请登录之后再选课');
    }
    $query="select father_module_id from son_module where id={$_GET['son_module_id']}";
    $result_id=execute($link,$query);
    if(mysqli_affected_rows($link)==1){
        $course_id=mysqli_fetch_assoc($result_id);
        $query="select * from select_class where id={$member_id} and son_module_id={$_GET['son_module_id']} and father_module_id={$course_id['father_module_id']}";
        execute($link,$query);
        if(mysqli_affected_rows($link)==1){
            skip('index.php','error','你已经选过该门课程请不要重复选课！');
            exit();
        }
        $query="insert into select_class (id,son_module_id,father_module_id) values({$member_id},{$_GET['son_module_id']},{$course_id['father_module_id']})";
        execute($link,$query);
        if(mysqli_affected_rows($link)==1){
            skip("list_son.php?id={$_GET['son_module_id']}",'ok','选课成功！');
            exit();
        }else{
            skip('index.php','error','选课失败，请重试！');
            exit();
        }
        exit();
    }else{
        skip('index.php','error','该课程暂无教师');
        exit();
    }
?>