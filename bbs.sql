-- 创建数据库
create database bbs default character set utf8 collate utf8_general_ci;
 
-- 建表
use bbs;
create table father_module(
    id int(10) unsigned not null auto_increment,
    module_name varchar(66) not null,
    sort int(11) default '0',
    primary key(id)
    )engine=myisam default charset=utf8 comment='父板块信息表'
    auto_increment=2;

create table son_module(
	id int(10) unsigned auto_increment primary key,
	father_module_id int(10),
	module_name varchar(66),
	info varchar(255),
	member_id int(10) unsigned default '0', -- 会员
	sort int(11) default '0'
);
create table member(
    id int(10) unsigned auto_increment primary key,
    name varchar(32),
    pw varchar(32),
    photo varchar(255),
    register_time datetime,
    last_time datetime
);
create table content(
    id int(10) unsigned auto_increment primary key,
    module_id int(10) unsigned,
    title varchar(255),
    content text,
    time datetime,
    member_id int(10),
    times int(10)
);
create table reply(
    id int(10) unsigned auto_increment primary key,
    content_id int(10) unsigned,
    quote_id int(10) unsigned default 0,
    content text,
    time datetime,
    member_id int(10) unsigned
);
create table manage(
    id int(10) unsigned auto_increment primary key,
    name varchar(32),
    pw varchar(32),
    createtime datetime,
    level tinyint(4)
);
create table collect(
    id int(10) unsigned auto_increment primary key,
    content_id int(10) unsigned,
    member_id int(10) unsigned,
    time datetime,
);
create table info(
    id int(10) unsigned auto_increment primary key,
    title varchar(255),
    keywords varchar(255),
    description varchar(255)
);

-- 视图
create view v1 as select content_id from collect;
-- 索引
create index index_father_module_name on father_module(module_name);
create index index_son_module_name on son_module(module_name);
-- 存储过程
delimiter $
create procedure insert_web_set(in a varchar(255),in b varchar(255),in c varchar(255))
begin
	update info set title=a,keywords=b,description=c where id=1;
end $
delimiter ;
-- 触发器
delimiter $ 
create trigger before_insert_web_set before insert on info for each row
begin
    select count(*) from manage into @cnt;
    if(@cnt+1>100) then 
		insert into XXX values(XXX);
	end if;
end
delimiter ;

delimiter $ 
create trigger after_delete_content after delete on content for each row
begin
    delete from reply where content_id not in (select id from content);
end
delimiter ;