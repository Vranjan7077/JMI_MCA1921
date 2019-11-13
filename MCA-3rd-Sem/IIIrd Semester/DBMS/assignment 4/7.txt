--Problem : Write a pl/sql code to compute area and perimeter of a circle
declare
      radius real;
      pi constant real := 3.14159;
begin
      radius := :Enter_Radius;
     
      dbms_output.put_line('Area          : ' || pi * radius * radius);
      dbms_output.put_line('Circumference : ' || 2 * pi * radius);
end;