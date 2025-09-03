<?php
include_once '../inc/config.inc.php';
include_once '../inc/mysql.inc.php';
include_once '../inc/tool.inc.php';
$link=connect();
include_once 'inc/is_manage_login.inc.php';
if(!is_manage_login($link)){
	skip('login.php','error','请先登录');
	exit();
}
$query="select * from info where id=1;";
$result_info=execute($link,$query);
$data_info=mysqli_fetch_assoc($result_info);
$template['title']='站点设置';
$template['css']=array('style/public.css');
if(isset($_POST['submit'])){
	$_POST=escape($link,$_POST);
	$query="call insert_web_set('{$_POST['title']}','{$_POST['keywords']}','{$_POST['description']}')";
	execute($link,$query);
	if(mysqli_affected_rows($link)==1){
		skip('web_set.php','ok',"修改成功!");
		exit();
	}else{
		skip('web_set.php','error',"修改失败!");
		exit();
	}
}
?>
<?php include 'inc/header.inc.php' ?>
<div id="main">
    <div class="title">网站设置</div>
    <form method="post">
        <table class="au">
			<tr>
				<td>网站标题</td>
				<td><input name="title" type="text" value="<?php echo $data_info['title']?>" /></td>
				<td>
					就是前台页面的网站标题
				</td>
			</tr>
			<tr>
				<td>关键字</td>
				<td><input name="keywords" type="text" value="<?php echo $data_info['keywords']?>"/></td>
				<td>
					关键字
				</td>
			</tr>
            <tr>
				<td>简介信息</td>
				<td>
                    <textarea name="description"><?php echo $data_info['description']?></textarea>
                </td>
				<td>
					板块简介不得为空，最大不得超过255个字符
				</td>
			</tr>
        </table>
        <input style="cursor:pointer;" class="btn" type="submit" name="submit" value="设置" />
    </form>
</div>
<?php include 'inc/footer.inc.php' ?>