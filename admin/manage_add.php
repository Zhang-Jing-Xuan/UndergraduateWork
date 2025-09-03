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
if(basename($_SERVER['SCRIPT_NAME'])=='manage_delete.php'||basename($_SERVER['SCRIPT_NAME'])=='manage_add.php'){
    if($_SESSION['manage']['level']!='0'){
        if(!isset($_SERVER['HTTP_REFERER'])){
            $_SERVER['HTTP_REFERER']='index.php';
        }
        skip($_SERVER['HTTP_REFERER'],'error','对不起，您不是超级管理员,无法添加其他管理员');
        exit();
    }
}
$template['title']='管理员添加页';
$template['css']=array('style/public.css');
if(isset($_POST['submit'])){
    include 'inc/check_manage_module.inc.php';
    $query="insert into manage(name,pw,create_time,level) values('{$_POST['name']}',md5({$_POST['pw']}),now(),{$_POST['level']})";
    execute($link,$query);
    if(mysqli_affected_rows($link)==1){
        skip('manage.php','ok','恭喜你添加成功');
    }else{
        skip('manage_add.php','error','对不起，添加失败');
    }
    exit();
}
?>
<?php include 'inc/header.inc.php' ?>
<div id="main">
    <div class="title">添加管理员</div>
    <form method="post">
        <table class="au">
			<tr>
				<td>管理员名称</td>
				<td><input name="name" type="text" /></td>
				<td>
					名称不得为空，名称不得超过32个字符
				</td>
			</tr>
			<tr>
				<td>密码</td>
				<td><input name="pw"type="text" /></td>
				<td>
					不能少于6位
				</td>
			</tr>
            <tr>
				<td>等级</td>
				<td>
					<select name='level'>
                        <option value="1">普通管理员</option>
                        <option value="0">超级管理员</option>
                    </select>
				</td>
                <td>
                    请选择一个等级，默认为普通管理员
                </td>
			</tr>
        </table>
        <input style="cursor:pointer;" class="btn" type="submit" name="submit" value="添加" />
    </form>
</div>
<?php include 'inc/footer.inc.php' ?>