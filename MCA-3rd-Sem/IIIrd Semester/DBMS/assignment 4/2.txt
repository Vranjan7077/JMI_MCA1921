--Problem : Write a pl/sql code to check whether a number is prime or not.

declare
      num integer;
      isPrime boolean := true;
begin
      num := :Enter_Number;
    
      for i in 2..sqrt(num) loop
        if(mod(num, i) = 0) then
          isPrime := false;
          exit;    -- like break in c/cpp
        end if;
      end loop;

      if(isPrime = true) then
         dbms_output.put_line(num || ' is prime.');
      else
         dbms_output.put_line(num || ' is not prime.');
      end if;
end;