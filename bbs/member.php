<?php
    include_once 'inc/config.inc.php';
    include_once 'inc/mysql.inc.php';
    include_once 'inc/tool.inc.php';
    include_once 'inc/page.inc.php';
    $link=connect();
    $member_id=is_login($link);
    $is_manage_login=is_manage_login($link);
    if(!isset($_GET['id'])||!is_numeric($_GET['id'])){
        skip('index.php','error','id参数错误');
        exit();
    }
    $query="select * from member where id={$_GET['id']}";
    $result_member=execute($link,$query);
    if(mysqli_num_rows($result_member)!=1){
        skip('index.php','error','会员不存在');
        exit();
    }
    $query="select count(*) from content where member_id={$_GET['id']}";
    $count_all=num($link,$query);
    $query="select count(*) from collect where member_id={$_GET['id']}";
    $count_collect=num($link,$query);
    $data_member=mysqli_fetch_assoc($result_member);
    $template['title']='会员中心';
    $template['css']=array('style/public.css','style/list.css','style/member.css');
?>
<?php include 'inc/header.inc.php' ?>
<div id="position" class="auto">
    <a href="index.php">首页</a> &gt;<?php echo $data_member['name']?>
</div>
<div id="main" class="auto">
    <div id="left">
        已发布的帖子
        <ul class="postsList">
            <?php
                $page=page($count_all,3);
                $query="select content.title,content.id,content.time,content.member_id,content.times,member.name,member.photo 
                from content,member where content.member_id={$_GET['id']} 
                and content.member_id=member.id {$page['limit']}";
                $result_content=execute($link,$query);
                while($data_content=mysqli_fetch_assoc($result_content)){
                    $data_content['title']=htmlspecialchars($data_content['title']);
                    $query="select time from reply where content_id={$data_content['id']} order by id desc limit 1";
                    $result_last_reply=execute($link,$query);
                    if(mysqli_num_rows($result_last_reply)==0){
                        $last_time='暂无';
                    }else{
                        $data_last_reply=mysqli_fetch_assoc($result_last_reply);
                        $last_time=$data_last_reply['time'];
                    }
                    $query="select count(*) from reply where content_id={$data_content['id']}";
            ?>
            <li>
                <div class="smallPic">
                        <img width="45" height="45" src="<?php if($data_content['photo']!=''){echo SUB_URL.$data_content['photo'];}else{echo 'style/photo.jpg';}?>" />
                </div>
                <div class="subject">
                <div class="titleWrap"><h2><a target='_blank' href="show.php?id=<?php echo $data_content['id']?>"><?php echo $data_content['title']?></a></h2></div>
                    <p>
                        发贴日期：<?php echo $data_content['time']?>&nbsp;&nbsp;&nbsp;&nbsp;最后回复：<?php echo $last_time?></br>
                        <?php
                            if(check_user($member_id,$data_content['member_id'],$is_manage_login)){
                                $url="content_delete.php?id={$data_content['id']}";
                                $return_url=urlencode($_SERVER['REQUEST_URI']);
                                $message="你真的要删除帖子{$data_content['title']}吗？";
                                $delete_url="confirm.php?url={$url}&return_url={$return_url}&message={$message}";
                                echo "<a href='content_update.php?id={$data_content['id']}'>编辑</a>&nbsp;<a href='{$delete_url}'>删除</a>" ;
                            }
                        ?>
                    </p>
                </div>
                <div class="count">
                <p>
                        回复<br /><span><?php echo num($link,$query);?></span>
                    </p>
                    <p>
                        浏览<br /><span><?php echo $data_content['times']?></span>
                    </p>
                </div>
                <div style="clear:both;"></div>
            </li>
            <?php }?>
        </ul>
        <div class="pages">
            <?php
                echo $page['html'];
            ?>
        </div>
    </div>
    <div id="right">
        <div class="member_big">
            <dl>
                <dt>
                    <img width="180" height="180" src="<?php if($data_member['photo']!=''){echo SUB_URL.$data_member['photo'];}else{echo 'style/photo.jpg';}?>" />
                </dt>
                <dd class="name"><?php echo $data_member['name']?></dd>
                <dd>帖子总计：<?php echo $count_all?></dd>
                <?php
                    if($member_id==$data_member['id']){
                ?>
                <dd>操作：<a target="_blank" href="member_photo_update.php">修改头像</a> <!--| <a target="_blank" href="">修改密码</a></dd>-->
                    <?php }?>
            </dl>
            <div style="clear:both;"></div>
        </div>
    </div>
    <div style="clear:both;"></div>
</div>




<div id="main" class="auto">
    <div id="left">
        <h2>已收藏的帖子</h2>
        <ul class="postsList">
            <?php
                $page=page($count_collect,3);
                // $query_view="create view v1 as select content_id from collect";
                // $result_flag=execute($link,$query_view);

                $query="select collect.id cid,content.title,content.id,collect.time,content.member_id,content.times,member.name,member.photo 
                from content,member,collect where content.id in (select * from v1) and collect.content_id =content.id
                and content.member_id=member.id and collect.member_id={$_GET['id']} {$page['limit']} ";
                $result_content=execute($link,$query);
                while($data_content=mysqli_fetch_assoc($result_content)){
                    $data_content['title']=htmlspecialchars($data_content['title']);
                    $query="select count(*) from reply where content_id={$data_content['id']}";
            ?>
            <li>
                <div class="smallPic">
                        <img width="45" height="45" src="<?php if($data_content['photo']!=''){echo SUB_URL.$data_content['photo'];}else{echo 'style/photo.jpg';}?>" />
                </div>
                <div class="subject">
                <div class="titleWrap"><h2><a target='_blank' href="show.php?id=<?php echo $data_content['id']?>"><?php echo $data_content['title']?></a></h2></div>
                    <p>
                        收藏日期：<?php echo $data_content['time']?>&nbsp;&nbsp;&nbsp;&nbsp;</br>
                        <?php
                            
                            $url="collect_delete.php?id={$data_content['cid']}";
                            $return_url=urlencode($_SERVER['REQUEST_URI']);
                            $message="你真的要取消收藏帖子{$data_content['title']}吗？";
                            $delete_url="confirm.php?url={$url}&return_url={$return_url}&message={$message}";
                            echo "<a href='{$delete_url}'>取消收藏</a>" ;
                            
                        ?>
                        
                    </p>
                </div>
                <div class="count">
                    <p>
                        回复<br /><span><?php echo num($link,$query);?></span>
                    </p>
                    <p>
                        浏览<br /><span><?php echo $data_content['times']?></span>
                    </p>
                </div>
                <div style="clear:both;"></div>
            </li>
            <?php }?>
        </ul>
        <div class="pages">
            <?php
                echo $page['html'];
            ?>
        </div>
    </div>
    <div style="clear:both;"></div>
</div>
<?php include 'inc/footer.inc.php' ?>