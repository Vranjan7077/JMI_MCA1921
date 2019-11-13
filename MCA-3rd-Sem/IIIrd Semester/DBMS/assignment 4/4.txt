--Problem : Write a pl/sql code to compute factorial of a given number.

declare
      n integer;
      fact integer := 1;
      i integer;
begin
      n := :Enter_Number;
      for i in reverse 1..n loop
         fact := fact * i;
      end loop;

      dbms_output.put_line('Factorial of ' || n || ' : ' || fact);
end;