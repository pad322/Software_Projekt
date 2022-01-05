
--Creating the tables
create table Players(
   Player_ID number
   generated always as identity primary key,
   Player_name varchar(30) not null,
   Email_address varchar(50) not null,
   Player_password varchar(20) not null
);

create table Results(
   Result_id number
   generated always as identity primary key,
   Score Double precision not null,
   Player_ID number references Players(Player_ID)
);

--Testing 
select * from players;
select * from results;

--Testing insert

insert into Players(
    Player_name,
    Email_address,
    Player_password)
    values(
    'Stoica Attila',
    'stoica.attila@student.ms.sapientia.ro',
    'chpc1122'
    )
;
insert into Players(
    Player_name,
    Email_address,
    Player_password)
    values(
    'Török Csongor',
    'torok.csongor@student.ms.sapientia.ro',
    'tppad57'
    )
;

insert into Results(
     Score,
     Player_ID)
     values(
     36.5,
     1
     )
;

--Testing update
update results
set score=49.03
where player_id=1;

--Query with join
select r.score
from
players p join results r
on p.Player_ID = r.Player_ID;

--Testing delete
delete from players
where player_id=2;





