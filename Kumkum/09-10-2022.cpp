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

select  sell_date, count(distinct product) as num_sold,
group_concat( distinct product order by product )  as products 
from Activities 
group by sell_date
order by 1 , 3;

