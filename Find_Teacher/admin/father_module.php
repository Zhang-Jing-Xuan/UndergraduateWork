<?php
//    error_reporting(E_ALL);
    include_once '../inc/config.inc.php';
	include_once '../inc/mysql.inc.php';
	include_once '../inc/tool.inc.php';
	$link=connect();
	if(isset($_POST['submit'])){
		foreach($_POST['sort'] as $key=>$val){
			if(!is_numeric($val)||!is_numeric($key)){
				skip('father_module.php','error','排序参数错误');
			}
			$query[]="update father_module set sort={$val} where id={$key}";
		}
		if(execute_multi($link,$query,$error)){
			skip('father_module.php','ok','排序修改成功');
			exit();
		}else{
			skip('father_module.php','error',$error);
			exit();
		}
	}
	$template['title']='课程列表页';
	$template['css']=array('style/public.css');
?>
<?php include 'inc/header.inc.php'?>
<div id="main" >
	<div class="title">课程列表</div>
	<form method='post'>
	<table class="list">
		<tr>
			<th>排序</th>	 	 	
			<th>课程名称</th>
			<th>操作</th>
		</tr>
		<?php
			$query='select * from father_module';
    			$result=execute($link,$query);
			while($data=mysqli_fetch_assoc($result)){
				//father_module_delete.php?id={$data['id']}
				$url="father_module_delete.php?id={$data['id']}";
				//var_dump($delete_url);
				$return_url=urlencode($_SERVER['REQUEST_URI']);
				//var_dump($return_url);
				$message="你真的要删除课程{$data['module_name']}吗？";
				$delete_url="confirm.php?url={$url}&return_url={$return_url}&message={$message}";
$html=<<<A
		<tr>
			<td><input class="sort" type="text" name="sort[{$data['id']}]" value="{$data['sort']}"/></td>
			<td>{$data['module_name']}[id:{$data['id']}]</td>
			<td><a href="#">[访问]</a>&nbsp;&nbsp;<a href="father_module_update.php?id={$data['id']}">[编辑]</a>&nbsp;&nbsp;<a href="$delete_url">[删除]</a></td>
		</tr>
A;
			echo $html;
			}
		?>	
	</table>
	<input style="cursor:pointer;" class="btn" type="submit" name="submit" value="修改排序" />
	</form>
</div>
<?php include 'inc/footer.inc.php'?>

