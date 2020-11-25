<?php 
include_once '../inc/config.inc.php';
include_once '../inc/mysql.inc.php';
include_once '../inc/tool.inc.php';
$template['title']='父板块添加页';
$template['css']=array('style/public.css','style/father_module_add.css');
$link=connect();
include_once '/inc/is_manage_login.inc.php';
if(!is_manage_login($link)){
    skip('login.php','error','请先登录');
    exit();
}
if(isset($_POST['submit'])){
    // var_dump($_POST);exit();
    
    //验证用户填写的内容
    $check_flag='add';
    include 'inc/check_father_module.inc.php';
    $query="insert into father_module(module_name,sort) values('{$_POST['module_name']}',{$_POST['sort']})";
    execute($link,$query);
    if(mysqli_affected_rows($link)==1){
        skip('father_module.php','ok','恭喜你添加成功');
    }else{
        skip('father_module_add.php','error','对不起，添加失败');
    }
    exit();
}
?>

<?php include 'inc/header.inc.php' ?>
<div id="main">
    <div class="title">添加父板块</div>
    <form method="post">
        <table class="au">
			<tr>
				<td>版块名称</td>
				<td><input name="module_name" type="text" /></td>
				<td>
					板块名称不得为空，最大不得超过66个字符
				</td>
			</tr>
			<tr>
				<td>排序</td>
				<td><input name="sort" value="0" type="text" /></td>
				<td>
					填写一个数字
				</td>
			</tr>
        </table>
        <input style="cursor:pointer;" class="btn" type="submit" name="submit" value="添加" />
    </form>
</div>
<?php include 'inc/footer.inc.php' ?>