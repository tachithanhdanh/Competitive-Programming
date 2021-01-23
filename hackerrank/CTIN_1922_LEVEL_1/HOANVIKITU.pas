(* Enter your code here. Read input from STDIN. Print output to STDOUT *)
var free:array[1..10] of boolean;
    s:string;
    i,j:integer;
    x:array[1..10] of char;
    tam:char;
procedure Try(i:integer);
    var j,k:integer;
        begin
            for j:=1 to length(s) do
                if free[j]=true then
                    begin
                        x[i]:=s[j];
                        free[j]:=false;
                        if i=length(s) then 
                            begin
                                for k:=1 to length(s) do write(x[k]);
                                writeln;
                            end else Try(i+1);
                        free[j]:=true;
                    end;
        end;

begin
fillchar(free,sizeof(i),false);
readln(s);
for i:=1 to length(s)-1 do
    for j:=i+1 to length(s) do
        if s[i]>s[j] then
            begin
                tam:=s[i]; s[i]:=s[j]; s[j]:=tam;
            end;
for i:=1 to length(s) do free[i]:=true;
Try(1);
end.