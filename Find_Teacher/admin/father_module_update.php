<?php
include_once '../inc/config.inc.php';
include_once '../inc/mysql.inc.php';
include_once '../inc/tool.inc.php';
$template['title']='修改课程';
$template['css']=array('style/public.css');
$link=connect();
if(!isset($_GET['id'])||!is_numeric($_GET['id'])){
	skip('father_module.php','error','该课程信息不存在！');
	exit();
}
$query="select * from father_module where id={$_GET['id']}";
$result=execute($link,$query);
if(!mysqli_num_rows($result)){
	skip('father_module.php','error','该课程信息不存在！');
	exit();
}
if(isset($_POST['submit'])){
	//验证用户填写的内容
	$check_flag='update';
	include 'inc/check_father_module.inc.php';
	$query="update father_module set module_name='{$_POST['module_name']}',sort={$_POST['sort']} where id={$_GET['id']}";
	execute($link,$query);
	if(mysqli_affected_rows($link)==1){
		skip('father_module.php','ok',"修改成功!");
	}else{
		skip('father_module.php','error',"修改失败!");
	}
	exit();
}
$data=mysqli_fetch_assoc($result);

?>
<?php include 'inc/header.inc.php' ?>
<div id="main">
    <div class="title">修改课程- <?php echo $data['module_name']?></div>
    <form method="post">
        <table class="au">
			<tr>
				<td>课程名称</td>
				<td><input name="module_name" value=<?php echo $data['module_name']?> type="text" /></td>
				<td>
					课程名称不得为空，最大不得超过66个字符
				</td>
			</tr>
			<tr>
				<td>排序</td>
				<td><input name="sort" value=<?php echo $data['sort']?> type="text" /></td>
				<td>
					填写一个数字
				</td>
			</tr>
        </table>
        <input style="cursor:pointer;" class="btn" type="submit" name="submit" value="修改" />
    </form>
</div?
<?php include 'inc/footer.inc.php' ?>