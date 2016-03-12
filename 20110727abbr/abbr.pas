const spe:array[1..10]of string=('i','pa','te','ni','niti','a','ali','nego','no','ili');
var ts,ss:string;
    t,cnt,i:longint;
    pd:boolean;
begin
assign(input,'abbr.in');
reset(input);
assign(output,'abbr.out');
rewrite(output);
readln(ts);
t:=pos(' ',ts);
cnt:=0;
while t<>0 do
 begin
 ss:=copy(ts,1,t-1);
 delete(ts,1,t);
 pd:=true;
 for i:=1 to 10 do
     if ss=spe[i] then begin pd:=false; break; end;
 inc(cnt);
 if (pd)or(cnt=1) then write(char(64+ord(ss[1])-96));
 t:=pos(' ',ts);
 end;
pd:=true;
for i:=1 to 10 do
    if ts=spe[i] then begin pd:=false; break; end;
inc(cnt);
if (pd) then write(char(64+ord(ts[1])-96));
writeln;
close(input);
close(output);
end.