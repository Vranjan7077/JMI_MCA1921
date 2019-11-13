declare
    x integer;
    y integer;
    z integer;
    result integer;
begin
    x := :Enter_Value_Of_X;
    y := :Enter_Value_Of_y;
    z := :Enter_Value_Of_z;

    if(x > y) then
        if(x > z) then
            result := x;
        else
            result := y;
        end if;
    else
        if(y > z) then
            result := y;
        else
            result := z;
        end if;
    end if;
    dbms_output.put_line('Greatest among ' || x || ', ' || y || ', ' || z || ' is : ' || result);
end;