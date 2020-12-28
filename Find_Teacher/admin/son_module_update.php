<?php
include_once '../inc/config.inc.php';
include_once '../inc/mysql.inc.php';
include_once '../inc/tool.inc.php';
$template['title']='教师管理页';
$template['css']=array('style/public.css');
$link=connect();
if(!isset($_GET['id'])||!is_numeric($_GET['id'])){
	skip('son_module.php','error','该课程不存在！');
	exit();
}
$query="select * from son_module where id={$_GET['id']}";
$result=execute($link,$query);
if(!mysqli_num_rows($result)){
	skip('son_module.php','error','教师信息不存在！');
	exit();
}
$data=mysqli_fetch_assoc($result);
if(isset($_POST['submit'])){
	$check_flag='update';
	include 'inc/check_son_module.inc.php';
	/*
	
	*/
	$query="update son_module set father_module_id={$_POST['father_module_id']},module_name='{$_POST['module_name']}',info='{$_POST['info']}',member_id={$_POST['member_id']},sort={$_POST['sort']} where id={$_GET['id']}";
	execute($link,$query);
	if(mysqli_affected_rows($link)==1){
		skip('son_module.php','ok',"修改成功!");
	}else{
		skip('son_module.php','error',"修改失败!");
	}
	exit();
}
?>
<?php include 'inc/header.inc.php' ?>
<div id="main">
    <div class="title">教师信息修改-<?php echo $data['module_name']?></div>
    <form method="post">
        <table class="au">
            <tr>
				<td>所教授课程</td>
				<td>
					<select name="father_module_id"> 
                        <option value="0">请选择一个课程</option>
						<?php
							$query="select * from father_module";
							$result_father=execute($link,$query);
							while($data_father=mysqli_fetch_assoc($result_father)){
								if($data_father['id']==$data['father_module_id']){
									echo "<option selected='selected' value='{$data_father['id']}'>{$data_father['module_name']}</option>";
								}else{
									echo "<option value='{$data_father['id']}'>{$data_father['module_name']}</option>";
								}
								
							}
						?>
                    </select>
				</td>
				<td>
					必须选择一个所属的课程
				</td>
			</tr>
			<tr>
				<td>课程名称</td>
				<td><input name="module_name" value="<?php echo $data['module_name']?>"type="text" /></td>
				<td>
					课程名称不得为空，最大不得超过66个字符
				</td>
			</tr>
            <tr>
				<td>简介信息</td>
				<td>
                    <textarea name="info"><?php echo $data['info']?></textarea>
                </td>
				<td>
					教师简介不得为空，最大不得超过255个字符
				</td>
			</tr>
			<tr>
				<td>排序</td>
				<td><input name="sort" value="<?php echo $data['sort']?>" type="text" /></td>
				<td>
					填写一个数字
				</td>
			</tr>
        </table>
        <input style="cursor:pointer;" class="btn" type="submit" name="submit" value="修改" />
    </form>
</div>
<?php include 'inc/footer.inc.php' ?>