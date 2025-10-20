create Database if not exists exam_db;
use exam_db;

create table users(
    user_id int auto_increment primary key,
    username varchar(50),
    password carchar(128) not null,
    role ENUM('admin','student') NOT NULL
);

create table questions(
    question_id int auto_increment primary key,
    question_text text not null,
    option1 varchar(200),
    option2 varchar(200),
    option3 varchar(200),
    option4 varchar(200),
    correct_option int
);

create table results (
    result_id int auto_increment primary key,
    user_id int,
    score int,
    total int,
    taken_on datetime default current_timestamp,
    foreign key (user_id) references users(user_id)
);

insert ignore into users(username, password, role) values ('admin', '123', 'admin');