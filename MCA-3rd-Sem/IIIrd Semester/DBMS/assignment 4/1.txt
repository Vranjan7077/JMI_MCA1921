create table customers4( cnum number(4) constraint PK_CUSTOMERS4_CNUM primary key,
                         cname varchar2(30) constraint NN_CUSTOMERS4_CNAME not null,
                         city varchar2(30) constraint NN_CUSTOMERS4_CITY not null,
                         pin number(6) constraint CK_CUSTOMERS4_PIN check (pin > 99999 and pin < 1000000),
                         state varchar2(30) constraint NN_CUSTOMERS4_STATE not null
);


create table suppliers4( snum number(4) primary key,
                         sname varchar2(30) not null,
                         state varchar2(50) not null,
                         pin number(6) check (pin > 99999 and pin < 1000000),
                         contactno number(10) check (contactno > 999999999 and contactno < 10000000000),
                         address varchar2(50)
);

create table productcatagory4( catagorynum number(4) primary key,
                               catagoryname varchar2(30) not null
);

create table products4( pnum number(4) primary key,
                        mrp number(8, 2) not null,
                        pcatagorynum number(4) references productcatagory4(catagorynum),
                        snum number(4) references suppliers4(snum), 
                        pname varchar2(30)
);


create table paymentmethods( methodnum number(3) primary key,
                             name varchar2(30) not null
);

create table orders4( onum number(4) primary key,
                      odate date not null,
                      payment_mode number(3) references paymentmethods(methodnum),
                      cnum number(4) references customers4(cnum),
                      pnum number(4) references products4(pnum),
                      amount number(8,2) not null,
                      quantity number(3) not null                   
);

desc customers4;
select * from customers4;
insert into customers4 values (:Customer_Number, :Name, :City, :PIN, :State);

desc suppliers4;
select * from suppliers4;
insert into suppliers4 values(:Supplier_Number, :Name, :State, :Pin, :Contact_NO, :Address);

desc productcatagory4;
select * from productcatagory4;
insert into productcatagory4 values(:Catagory_Number, :Catagory_Name, :Product_Name);

desc paymentmethods;
select * from paymentmethods;
insert into paymentmethods values(:Method_Number, :Name);

desc products4;
select * from products4;
insert into products4 values(:Product_Number, :Product_Catagory_Number, :Supplier_Number);

desc orders4;
select * from orders4;
insert into orders4 values(:Orders_Number, :Order_Date, :Payment_Mode, :Customer_Numbers, :Product_Number, :Amt, :Quantity);

--a)
select * from customers4 where lower(cname) like 'p%'

--b)
select snum as "Supplier Number", sname as "Name" from suppliers4 where snum in (select snum from products4 where pcatagorynum = (select catagorynum from productcatagory4 where catagoryname = 'Kitchen'));

--c)
select sum(amount* quantity) "Total Sales" from orders4 where extract(month from odate) = 3 and extract(year from odate) = 2018

--d)
select cnum "Customer No", max(amount * quantity) "MAX Order Amount", min(amount * quantity) "MIN Order Amount" from orders4 group by cnum;

--e)
??????????????????????
select * from products4
select * from orders4
select pnum from orders4 where extract(month from odate) in (6, 7, 8) and extract(year from odate) = 2018;
-- or use group by
?????????????????????????/


--f)
##############3
select * from orders4;

select cnum from orders4 group by odate extract(month from odate)
########

--g)
select ( select cname from customers4 where cnum = o.cnum) "Name", (select name from paymentmethods where methodnum = o.payment_mode) "Payment Mode", (select pname from products4 where pnum = o.pnum) "Product" from orders4 o 
 
--h)
select cnum "Customer No.", cname "Name", state "State", pin "PIN", city "City" from customers4 order by state, pin, city

--i)
create view productAndCatagoryView as select p.pnum "Product No.", pc.catagoryname "Catagory" from products4 p, productcatagory4 pc where p.pcatagorynum = pc.catagorynum;
select * from productAndCatagoryView; 

--j)
?????????????????
select count(*), cnum from orders4 group by cnum
???????????????????
--k)
select sname from suppliers4 where snum in ( select snum from products4 group by snum having count(*) > 1)

--l)
???????????? fetch records only for last yr ??????????????
select o.pnum, count(*) from orders4 o group by pnum order by count(*)
????????????????
--m)
select o.cnum "Customer No.", (select cname from customers4 where cnum = o.cnum) "Name", sum(o.amount * o.quantity) "Amount" from orders4 o group by o.cnum having sum(o.amount * o.quantity) > (select max(amount*quantity) from orders4);

--n)
select o.cnum "Customer No.",(select cname from customers4 where cnum = o.cnum) "Name" ,  o.odate "Date", o.pnum "Product No.",(select pname from products4 where pnum = o.pnum) "Name" , o.amount "Amount", o.quantity "Qty", o.amount * o.quantity "Total" from orders4 o where (o.odate, o.amount* o.quantity) in (select odate, max(amount*quantity) from orders4  group by odate)
union all
select o.cnum "Customer No.",(select cname from customers4 where cnum = o.cnum) "Name" ,  o.odate "Date", o.pnum "Product No.",(select pname from products4 where pnum = o.pnum) "Name" , o.amount "Amount", o.quantity "Qty", o.amount * o.quantity "Total" from orders4 o where (o.odate, o.amount* o.quantity) in (select odate, min(amount*quantity) from orders4  group by odate) order by 3;

--as odate is the third column that is why we use 'order by 3' in order to list them date wise;