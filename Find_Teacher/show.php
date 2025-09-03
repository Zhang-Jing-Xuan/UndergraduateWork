<?php
include_once 'inc/config.inc.php';
include_once 'inc/mysql.inc.php';
include_once 'inc/tool.inc.php';
include_once 'inc/page.inc.php';
$link=connect();
$member_id=is_login($link);
if(!isset($_GET['id'])||!is_numeric($_GET['id'])){
    skip('index.php','error','id参数错误');
    exit();
}
$query="select sc.id cid,sc.module_id,sc.title,sc.content,sc.time,sc.member_id,sc.times,sm.name,sm.photo,sm.role from content sc,member sm where sc.id={$_GET['id']} and sc.member_id=sm.id";
$result_content=execute($link,$query);
if(mysqli_num_rows($result_content)!=1){
    skip('index.php','error','帖子不存在');
    exit();
}
$query="update content set times=times+1 where id={$_GET['id']};";
execute($link,$query);
$data_content=mysqli_fetch_assoc($result_content);
$data_content['times']=$data_content['times']+1;
$data_content['title']=htmlspecialchars($data_content['title']);
$data_content['content']=nl2br(htmlspecialchars($data_content['content']));
$query="select * from son_module where id={$data_content['module_id']}";
$result_son=execute($link,$query);
$data_son=mysqli_fetch_assoc($result_son);

$query="select * from father_module where id={$data_son['father_module_id']}";
$result_father=execute($link,$query);
$data_father=mysqli_fetch_assoc($result_father);

$query="select count(*) from reply where content_id={$_GET['id']}";
$count_reply=num($link,$query);
$template['title']='帖子详细页';
$template['css']=array('style/public.css','style/show.css');
?>
<?php include 'inc/header.inc.php' ?>
<div id="position" class="auto">
		 <a href="index.php">首页</a> &gt; <a href=list_father.php?id=<?php echo $data_father['id']?>><?php echo $data_father['module_name']?></a> &gt; <a href=list_son.php?id=<?php echo $data_son['id']?>><?php echo $data_son['module_name'];?></a> &gt; <?php echo $data_content['title']?>
</div>
<div id="main" class="auto">
    <div class="wrap1">
        <div class="pages">
        <?php 
        $query="select count(*) from reply where content_id={$_GET['id']}";
        $count_reply=num($link,$query);
        $page_size=5;
        $page_reply=page($count_reply,$page_size);
        echo $page_reply['html'];
        ?>
        </div>
        <a class="btn reply" href="reply.php?id=<?php echo $_GET['id']?>"></a>
        <div style="clear:both;"></div>
    </div>
    <?php
        if(!isset($_GET['page'])||$_GET['page']==1){

        
    ?>
    <div class="wrapContent">
        <div class="left">
            <div class="face">
                <a target="_blank" href="">
                    <img width=120 height=120 src="<?php if($data_content['photo']!=''){echo $data_content['photo'];}else{echo 'style/photo.jpg';}?>" />
                </a>
            </div>
            <div class="name">
                <a href=""><?php echo $data_content['name']?></a>
            </div>
        </div>
        <div class="right">
            <div class="title">
                <h2><?php echo $data_content['title']?></h2>
                <span>阅读：<?php echo $data_content['times']?>&nbsp;|&nbsp;回复：<?php echo $count_reply;?></span>
                <div style="clear:both;"></div>
            </div>
            <div class="pubdate">
                <span class="date">发布于：<?php echo $data_content['time']?></span>
                <?php
                    $role="教师";
                    if($data_content['role']=="student"){
                        $role="学生";
                    }
                ?>
                <span class="floor" style="color:red;font-size:14px;font-weight:bold;"><?php echo $role;?></span>
            </div>
            <div class="content">
            <?php echo $data_content['content']?>
            </div>
        </div>
        <div style="clear:both;"></div>
    </div>
    <?php }?>
    <?php
        $query="select m.name,r.member_id,m.photo,r.time,r.quote_id,r.id,r.content from reply r,member m where r.member_id=m.id and r.content_id={$_GET['id']} order by id asc {$page_reply['limit']}";
        // var_dump($query);exit();
        $result_reply=execute($link,$query);
        $i=($_GET['page']-1)*$page_size+1;
        while($data_reply=mysqli_fetch_assoc($result_reply)){

        
    ?>
    <div class="wrapContent">
        <div class="left">
            <div class="face">
                <a target="_blank" href="">
                <img width=120 height=120 src="<?php if($data_reply['photo']!=''){echo $data_reply['photo'];}else{echo 'style/photo.jpg';}?>" />
                </a>
            </div>
            <div class="name">
                <a href=""><?php echo $data_reply['name']?></a>
            </div>
        </div>
        <div class="right">
            
            <div class="pubdate">
                <span class="date">回复时间：<?php echo $data_reply['time']?></span>
                <?php
                    $query="select member.role from reply,member where reply.id={$data_reply['id']} and reply.member_id=member.id";
                    $result_role=execute($link,$query);
                    $result_role=mysqli_fetch_assoc($result_role);
                    if($result_role['role']=="teacher"){
                        $role="教师";
                    }
                ?>
                <span class="floor" style="color:red;font-size:14px;font-weight:bold;"><?php echo $role;?></span>
                <!-- <span class="floor"><?php echo $i++;?>楼&nbsp;|&nbsp;<a target="_blank" href="quote.php?id=<?php echo $_GET['id'];?>&reply_id=<?php echo $data_reply['id'];?>">引用</a></span> -->
            </div>
            <div class="content">
                <?php
                    if($data_reply['quote_id']){
                        $query="select count(*) from reply where content_id={$_GET['id']} and id<={$data_reply['quote_id']}";
                        $floor=num($link,$query);
                        $query="select reply.content,member.name from reply,member where reply.id={$data_reply['quote_id']} and reply.member_id=member.id";
                        $result_quote=execute($link,$query);
                        $data_quote=mysqli_fetch_assoc($result_quote);
                ?>
                <div class="quote">
                    <h2>引用<?php echo $floor?>楼<?php echo $data_quote['name']?>发表的：</h2>
                    <?php echo nl2br(htmlspecialchars($data_quote['content']))?>
                </div>
        <?php }?>
            <?php 
            $data_reply['content']=nl2br(htmlspecialchars($data_reply['content']));
            echo $data_reply['content']
            ?>
            </div>
        </div>
        <div style="clear:both;"></div>
    </div>
    <?php 
        }
    ?>
    <div class="wrap1">
        <div class="pages">
        <?php
        echo $page_reply['html'];
        ?>
        </div>
        <!-- <a href="reply.php?id=<?php echo $_GET['id']?>"><img src="./style/reply.png" align="right"></a> -->
        <a class="btn reply" href="reply.php?id=<?php echo $_GET['id']?>"></a>
        <div style="clear:both;"></div>
    </div>
</div>
<?php include 'inc/footer.inc.php' ?>