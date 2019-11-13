create table customers3(id number(3) primary key, name varchar(30), age number(3), address varchar2(30), salary number(7, 2));

select * from customers3;
desc customers3;

insert into customers3 values(:ID, :Name, :Age, :Address, :Salary);

-- a)
create view view1 as select id, name, age from customers3;

select * from view1;

-- b)
create view view2 as select * from customers3 where salary > 5000;
select * from view2;

-- c)
insert into view1 values(016, 'John', NULL); -- changes will be reflected in both( In view1 view as well as in customer3 table)
select * from view1;
select * from customers3;

-- d)
update customers3 set name = 'ABC' where name = 'Komal'; -- changes will be reflected in both( In view1 view as well as in customer3 table)
select * from view1;
select * from customers3;

-- e)
update view2 set salary = 15000, age = 26 where name = 'Muffy'; -- changes will be reflected in both (In view1 view as well as in customer3 table)
select * from customers3;
select * from view2;

-- f)
delete from view1 where id = 004; -- changes will be reflected in both( In view1, view2 view as well as in customer3 table)
select * from view1;
select * from view2;
select * from customers3;

-- g)
drop view view2;
select * from customers3

-- h)
create view view3 as select name, age from customers3 where age is not null with check option constraint view3;
select * from view3
insert into view3 (name, age)values('Rohan', NULL); 
insert into view3 (name, age)values('Joe', 42);

-- the above can't be inserted in the customers3 table because table has 'ID' as primary key as we are not passing any value for ID field(CTM: Primary Key can't be NULL and must be Uniue)