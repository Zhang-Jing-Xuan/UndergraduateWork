<?php
    date_default_timezone_set('Asia/Shanghai');
    session_start();
    define ('DB_HOST','127.0.0.1');
    define ('DB_USER','root');
    define ('DB_PASSWORD','271828');
    define ('DB_DATABASE','bbs');
    define ('DB_PORT',3306);
    define('SA_PATH',dirname(dirname(__FILE__)));
    define('SUB_URL',str_replace($_SERVER['DOCUMENT_ROOT'],'',str_replace('\\','/',SA_PATH)).'/');
    // echo str_replace($_SERVER['DOCUMENT_ROOT'],'',str_replace('\\','/',SA_PATH)).'/';
    // var_dump($_SERVER['DOCUMENT_ROOT']);
?>

