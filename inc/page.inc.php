<?php
function page($count,$page_size,$num_btn=10,$page='page'){
    // echo "{$_GET[$page]}<br>";
    if(!isset($_GET[$page])||!is_numeric($_GET[$page])||$_GET[$page]<1){
        $_GET['page']=1;
    }
    if($count==0){
        $data=array(
            'limit'=>'',
            'html'=>''
        );
        return $data;
    }
    $page_num_all=ceil($count/$page_size);//总页码数
    if($_GET[$page]>$page_num_all){
        $_GET[$page]=$page_num_all;
    }
    $start=(($_GET[$page]-1)*$page_size);
    $limit="limit {$start},{$page_size}";
    $current_url=$_SERVER['REQUEST_URI'];
    $arr_current=parse_url($current_url);
    $current_path=$arr_current['path'];
    $url="";
    if(isset($arr_current['query'])){
        parse_str($arr_current['query'],$arr_query);
        unset($arr_query[$page]);
        if(empty($arr_query)){
            $url="{$current_path}?{$page}=";
        }else{
            $other=http_build_query($arr_query);
            $url="{$current_path}?{$other}&{$page}=";
        }
    }else{
        $url="{$current_path}?{$page}=";
    }
    $html=array();
    if($num_btn>=$page_num_all){
        for($i=1;$i<=$page_num_all;$i++){
            if($_GET[$page]==$i){
                $html[$i]="<span>{$i}</span>";
            }else{
                $html[$i]="<a href='{$url}{$i}'>{$i}</a>";
            }
        }
    }else{
        $num_left=floor(($num_btn-1)/2);
        // echo "{$_GET[$page]}<br>";
        // echo "{$num_left}<br>";
        $start=$_GET[$page]-$num_left;
        $end=$start+$num_btn-1;
        if($start<1){
            $start=1;
        }
        if($end>$page_num_all){
            $start=$page_num_all-$num_btn+1;
        }
        for($i=0;$i<$num_btn;$i++){
            if($_GET[$page]==$start){
                $html[$start]="<span>{$start}</span>";
            }else{
                $html[$start]="<a href='{$url}{$start}'>{$start}</a>";
            }
            $start++;
        }
        if(count($html)>=3){
            reset($html);
            $key_first=key($html);
            end($html);
            $key_end=key($html);
            if($key_first!=1){
                array_shift($html);
                array_unshift($html,"<a href='{$url}1'>1...</a>");
            }
            if($key_end!=$page_num_all){
                array_pop();
                array_push($html,"<a href='{$url}{$page_num_all}'>...{$page_num_all}</a>");
            }
        }
    }
    if($_GET[$page]!=1){
        $prev=$_GET[$page]-1;
        array_unshift($html,"<a href='{$url}{$prev}'>« 上一页</a>");
    }
    if($_GET[$page]!=$page_num_all){
        $next=$_GET[$page]+1;
        array_push($html,"<a href='{$url}{$next}'>下一页 »</a>");
    }
    $html=implode(' ',$html);
    $data=array(
        'limit'=>$limit,
        'html'=>$html
    );
    return $data;
}
?>