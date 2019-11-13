--Problem : Write a pl/sql code to display sum of first n natural numbers
declare
--    s integer := 0; --or 
      s number(3) := 0;
      n integer;
begin
   
      n:= :Enter_Value_n;
      for i in 1..n loop
        s := s + i;
      end loop;
      dbms_output.put_line(s);
end;