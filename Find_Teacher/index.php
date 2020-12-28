<?php
include_once 'inc/config.inc.php';
include_once 'inc/mysql.inc.php';
include_once 'inc/tool.inc.php';
$link=connect();
$member_id=is_login($link);
$template['title']='首页';
$template['css']=array('style/public.css','style/index.css');
?>
<?php include 'inc/header.inc.php' ?>
<div id="hot" class="auto">
<div class="title">热门课程/教师</div>
<ul class="newlist">
    <!-- 20条 -->
    <li><a href="#"></a> <a href="#">快来拜师</a></li>
</ul>
<div style="clear:both;"></div>
</div>

<?php
$query="select * from father_module order by sort desc";
$result_father=execute($link,$query);
while($data_father=mysqli_fetch_assoc($result_father)){
?>
<div class="box auto">
    <div class="title">
        <a href="list_father.php?id=<?php echo $data_father['id'];?>">
        <?php
            echo $data_father['module_name'];
        ?></a>
        
    </div>
    <div class="classList">
        <?php
            $query="select * from son_module where father_module_id={$data_father['id']}";
            $result_son=execute($link,$query);
            if(mysqli_num_rows($result_son)){
                while($data_son=mysqli_fetch_assoc($result_son)){
                    $query="select count(*) from content where module_id={$data_son['id']} and time>CURDATE() group by member_id";
                    $count_today=num($link,$query);
                    $query="select count(*) from select_class where son_module_id={$data_son['id']}";
                    $count_all=num($link,$query);
                    $html=<<<A
                        <div class="childBox new">
                            <h2><a href="list_son.php?id={$data_son['id']}">{$data_son['module_name']}</a> <span>(今日{$count_today})</span></h2>
                            学生：{$count_all}<br />
                        </div>
A;
                    echo $html;
                }
                /*
                <div class="childBox new">
                    <h2><a href="#">私队</a> <span>(今日38)</span></h2>
                    帖子：1939539<br />
                </div>
                */
            }else{
                echo '<div style="padding:10px 0;">暂无教师...</div>';
            }
        ?>
        <div style="clear:both;"></div>
    </div>
    </div>
<?php }?>
<?php include 'inc/footer.inc.php' ?>