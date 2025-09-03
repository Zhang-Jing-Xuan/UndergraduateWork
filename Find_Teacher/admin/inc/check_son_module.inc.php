<?php
    if(!is_numeric($_POST['father_module_id'])){
        skip('son_module_add.php','error','所属课程不得为空');
    }
    $query="select * from father_module where id={$_POST['father_module_id']}";
    $result=execute($link,$query);
    if(mysqli_num_rows($result)==0){
        skip('son_module_add.php','error','所属课程不存在');
        exit();
    }
    if(empty($_POST['module_name'])){
        skip('son_module_add.php','error','教师不得为空');
        exit();
    }
    if(mb_strlen($_POST['module_name'])>66){
        skip('son_module_add.php','error','教师名字不得多于66个字符');
        exit();
    }
    $_POST=escape($link,$_POST);
    switch($check_flag){
        case 'add':
            $query="select * from son_module where module_name='{$_POST['module_name']}'";
            break;
        case 'update':
            $query="select * from son_module where module_name='{$_POST['module_name']}' and id!={$_GET['id']}";
            break;
        default:
        skip('son_module.php','error','check_flag错误');
    }
    $result=execute($link,$query);
    if(mysqli_num_rows($result)){
        skip('son_module_add.php','error','教师已存在');
        exit();
    }
    if(mb_strlen($_POST['info'])>255){
        skip('son_module_add.php','error','教师简介不得多于255个字符');
        exit();
    }
    if(!is_numeric($_POST['sort'])){
        skip('son_module_add.php','error','排序只能是数字');
        exit();
    }
?>