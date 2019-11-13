-- ref : 
--Problem : Write a pl/sql code to compare three given numbers and display them in ascending order.
declare
    a integer;
    b integer;
    c integer;
begin
    a:= :Enter_Value_a;
    b:= :Enter_Value_b;
    c:= :Enter_Value_c;

    if(a <= b and a <= c) then
        if(b < c) then  -- now we know 'a' will be the first term, so find only who is the second term among (b,c) & print the remaining at third position.  
            dbms_output.put_line(a || ' ' || b || ' ' || c);
        else
            dbms_output.put_line(a || ' ' || c || ' ' || b);
        end if;
    elsif(b <= a and b <= c) then
        if(a < c) then -- now we know 'b' will be the first term, so find only who is the second term among (a, c) & print the remaining at third position.  
            dbms_output.put_line(b || ' ' || a || ' ' || c);
        else
            dbms_output.put_line(b || ' ' || c || ' ' || a);
        end if;
    elsif(a < b) then -- upto this point now we already know that 'c' will be the first term so find the second position among (a, b) & print the remaining at third position.
            dbms_output.put_line(c || ' ' || a || ' ' || b);
    else
            dbms_output.put_line(c || ' ' || b || ' ' || a);
    end if;
end;