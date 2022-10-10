//1
//sql- day 3

select user_id, 
concat(upper(substr(name,1,1)),lower(substr(name,2))) as name 
from Users
order by 1;

//2
//sql day-3

select * 
from Patients 
where 
conditions like "DIAB1%" 
or 
conditions like "% DIAB1%";

//3
//sql day-3

