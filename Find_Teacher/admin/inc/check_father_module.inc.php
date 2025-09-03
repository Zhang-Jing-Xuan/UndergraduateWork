<?php
if(empty($_POST['module_name'])){
    skip('father_module_add.php','error','课程名称不得为空');
    exit();
}
if(mb_strlen($_POST['module_name'])>66){
    skip('father_module_add.php','error','课程名称不得多于66个字符');
    exit();
}
if(!is_numeric($_POST['sort'])){
    skip('father_module_add.php','error','排序只能是数字');
    exit();
}
$_POST=escape($link,$_POST);
switch($check_flag){
    case 'add':
        $query="select * from father_module where module_name='{$_POST['module_name']}'";
        break;
    case 'update':
        $query="select * from father_module where module_name='{$_POST['module_name']}' and id!={$_GET['id']}";
        break;
    default:
    skip('father_module_add.php','error','check_flag错误');
}

$result=execute($link,$query);
if(mysqli_num_rows($result)){
    skip('father_module_add.php','error','课程名称已存在');
    exit();
}
?>