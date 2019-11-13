-- Department table Schema
create table dept3 (department_id number(3), department_name varchar2(20) not null,
                    primary key(department_id));

-- Employee table Schema
create table emp3(employee_id number(3), first_name varchar2(30), last_name varchar2(30), salary number(8, 2), department_id number(3),
                  primary key(employee_id),
                  foreign key(department_id) references dept3(department_id));

-- Inserting Data for Department
insert into dept3 values(20, 'Accounting');
insert into dept3 values(:Dept_ID, :Dept_Name);

-- Inserting Data for Employee
insert into emp3(employee_id, first_name, last_name, salary, department_id) values(111, 'Steven', 'King', 24000, 20);
insert into emp3 values(:Employee_ID, :F_Name, :L_name, :Salary, :Dept_ID);

select * from dept3;
desc dept3;

select * from emp3;
desc emp3

-- a)
select first_name || ' ' || last_name as "Name", salary from emp3 where salary > (select salary from emp3 where last_name = 'Hopkings');

-- b)
select first_name || ' ' || last_name as "Name" from emp3 where department_id = (select department_id from dept3 where department_name = 'IT');

-- c)
select first_name || ' ' || last_name as "Name", salary from emp3 where salary > (select avg(salary) from emp3);

--d)
select first_name || ' ' || last_name as "Name", salary from emp3 where salary > (select avg(salary) from emp3 where department_id = (select department_id from dept3 where department_name = 'IT'));

--e)
select * from emp3 where salary = (select min(salary) from emp3);

--f)
select * from emp3 where salary > (select avg(salary) from emp3);