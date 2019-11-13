--Problem : Write a pl/sql code to print fibonacci series.
declare
      term integer;
      term1 integer := 0;
      term2 integer := 1;
      n integer;
begin
      n:= :Number_Of_Terms_You_Want;
      
      dbms_output.put_line('Fibonacii Series of ' || n || ' terms :');
      if( n >= 1 ) then
        dbms_output.put_line(0);
      end if;
      
      if(n >= 2) then
        dbms_output.put_line(1);
      end if;
      
      for i in 1..n - 2 loop
         term := term1 + term2;
         dbms_output.put_line(term);
         term1 := term2;
         term2 := term;
      end loop;
end;