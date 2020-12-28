<?php
    date_default_timezone_set('Asia/Shanghai');
    define ('DB_HOST','127.0.0.1');
    define ('DB_USER','root');
    //9CB4ca81595d
    define ('DB_PASSWORD','271828');
    define ('DB_DATABASE','find_teacher');
    define ('DB_PORT',3306);
    define('SA_PATH',dirname(dirname(__FILE__)));
    define('SUB_URL',str_replace($_SERVER['DOCUMENT_ROOT'],'',str_replace('\\','/',SA_PATH)).'/');
    // echo str_replace($_SERVER['DOCUMENT_ROOT'],'',str_replace('\\','/',SA_PATH)).'/';
    // var_dump($_SERVER['DOCUMENT_ROOT']);
?>

