<?php
function upload($save_path,$custom_upload_max_filesize,$key,$type=array('jpg','jpeg','gif','png')){
    $return_data=array();
    $phpini=ini_get('upload_max_filesize');
    $phpini_unit=strtoupper(substr($phpini,-1));
    $phpini_number=substr($phpini,0,-1);
    $phpini_multiple=get_multiple($phpini_unit);
    $phpini_bytes=$phpini_number*$phpini_multiple;

    $custom_unit=strtoupper(substr($custom_upload_max_filesize,-1));
    $custom_number=substr($custom_upload_max_filesize,0,-1);
    $custom_multiple=get_multiple($custom_unit);
    $custom_bytes=$custom_number*$custom_multiple;

    if($custom_bytes>$phpini_bytes){
        $return_data['error']='传入的$custom_upload_max_filesize大于php配置文件的'.$phpini;
        $return_data['return']=false;
        return $return_data;
    }
    $arr_errors=array(
        0=>'没有错误',
        1=>'上传文件大小超过php.ini中的上限',
        2=>'上传文件大小超过html表单的值',
        3=>'文件部分上传',
        4=>'没有文件被上传',
        6=>'找不到临时文件夹',
        7=>'文件写入失败'
    );
    if(!isset($_FILES[$key]['error'])){
        $return_data['error']='上传失败，原因未知';
        $return_data['return']=false;
        return $return_data;
    }
    if($_FILES[$key]['error']!=0){
        $return_data['error']=$arr_errors[$_FILES[$key]['error']];
        $return_data['return']=false;
        return $return_data;
    }

    if(!is_uploaded_file($_FILES[$key]['tmp_name'])){
        $return_data['error']='该文件不是通过post发送的';
        $return_data['return']=false;
        return $return_data;
    }

    if($_FILES[$key]['size']>$custom_bytes){
        $return_data['error']='上传文件大小超过预定义值';
        $return_data['return']=false;
        return $return_data;
    }
    $arr_filename=pathinfo($_FILES[$key]['name']);
    if(!isset($arr_filename['extension'])){
        $arr_filename['extension']='';
    }
    if(!in_array($arr_filename['extension'],$type)){
        $return_data['error']='上传文件类型不符合！';
        $return_data['return']=false;
        return $return_data;
    }
    if(!file_exists($save_path)){
        if(!mkdir($save_path,0777,true)){
            $return_data['error']='上传失败';
            $return_data['return']=false;
            return $return_data;
        }
    }
    $new_filename=str_replace('.','',uniqid(mt_rand(1000,9999),true));
    if($arr_filename['extension']!=''){
        $new_filename.=".{$arr_filename['extension']}";
    }
    $save_path=rtrim($save_path,'/').'/';
    
    if(!move_uploaded_file($_FILES[$key]['tmp_name'],$save_path.$new_filename)){
        $return_data['error']='临时文件移动失败';
        $return_data['return']=false;
        return $return_data;
    }
    // var_dump($save_path.$new_filename);
    // var_dump($_FILES);
    $return_data['save_path']=$save_path.$new_filename;
    $return_data['filename']=$new_filename;
    $return_data['return']=true;
    return $return_data;
}

function get_multiple($unit){
    switch($unit){
        case 'K':
            $multiple=1024;
            return $multiple;
        case 'M':
            $multiple=1024*1024;
            return $multiple;
        case 'G':
            $multiple=1024*1024*1024;
            return $multiple;
        default:
            return false;
    }
}
header("Content-tyoe=text/html;charset=utf-8");
if(isset($_POST['submit'])){
    $upload=upload('a/','2M','myfile');
    if(!$upload['return']){
        var_dump($upload['error']);
    }else{
        echo '上传成功';
    }
}

?>
<!DOCTYPE html>
<html lang="zh-CN">
<head>
<meta charset="utf-8" />
<title>上传页面</title>
</head>
<body>
<form action="" method="post" enctype="multipart/form-data">
	<input type="file" name="myfile" />
	<input type="submit" name="submit" value="开始上传" />
</form>
</body>
</html>
