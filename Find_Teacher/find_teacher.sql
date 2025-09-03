create database find_teacher default character set utf8 collate utf8_general_ci; 
use find_teacher;
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
    last_time datetime,
    role varchar(45)
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


-- 
create table collect(
    id int(10) unsigned auto_increment primary key,
    content_id int(10) unsigned,
    member_id int(10) unsigned,
    time datetime
);