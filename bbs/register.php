<?php
include_once 'inc/config.inc.php';
include_once 'inc/mysql.inc.php';
include_once 'inc/tool.inc.php';
$link=connect();
if($member_id=is_login($link)){
	skip('index.php','error','你已经登录，请不要重复注册！');
	exit();
}

if(isset($_POST['submit'])){
	$link=connect();
	include 'inc/check_register.inc.php';
	$query="insert into member(name,pw,register_time)values('{$_POST['name']}',md5('{$_POST['pw']}'),now())";
	execute($link,$query);
	if(mysqli_affected_rows($link)==1){
		setcookie('zjx[name]',$_POST['name']);
		setcookie('zjx[pw]',sha1(md5($_POST['pw'])));
		skip("index.php",'ok','注册成功！');
		exit();
	}else{
		skip("register.php",'error','注册失败！');
		exit();
	}
	/*
	
	*/
}
$template['title']='会员注册页';
$template['css']=array('style/public.css','style/register.css');
?>
<?php include 'inc/header.inc.php' ?>
	<div id="register" class="auto">
		<h2>欢迎注册成为会员</h2>
		<form method="post">
			<label>用户名：<input type="text" name="name"/><span>*用户名不得为空，并且长度不得超过32个字符</span></label>
			<label>密码：<input type="password" name="pw"/><span>*密码不得少于6位</span></label>
			<label>确认密码：<input type="password" name="confirm_pw"/><span>*请输入与上面一致</span></label>
			<label>验证码：<input name="vcode" type="text" name="vcode"/><span>*请输入下方验证码</span></label>
			<img class="vcode" src="style/show_code.php.jpg" />
			<div style="clear:both;"></div>
			<input class="btn" name="submit" type="submit" value="确定注册" />
		</form>
	</div>
	<div id="footer" class="auto">
		<div class="bottom">
			<a>zjx</a>
		</div>
		<div class="copyright">Powered by zjx ©2020 127.0.0.1</div>
	</div>
</body>
</html>