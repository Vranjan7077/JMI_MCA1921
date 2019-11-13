--Problem : Write a pl/sql code to check wheter a number is palindrome or not.

declare
      num integer;
      numCopy integer;
      reverse integer := 0;
     begin
      num := :Enter_Number;
      numCopy := num;

      while(numCopy != 0) loop
        reverse := reverse * 10 + mod(numCopy, 10);
        numCopy := floor(numCopy / 10);      
      end loop;
           
      if(reverse = num) then
         dbms_output.put_line(num || ' is palindrome.');
      else
         dbms_output.put_line(num || ' is not a palindrome.');
      end if;
end;