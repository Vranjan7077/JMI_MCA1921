--Problem : Write a pl/sql code to display whether a number is even or odd.
declare
      number integer;
begin
      number:= :Enter_Number;
      
      if(mod(number, 2) = 0 ) then
        dbms_output.put_line(number || ' is even number.');
      else
        dbms_output.put_line(number || ' is odd number.');
      end if;
end;