# Write your MySQL query statement below

select r.contest_id, ROUND(count(*)/(select count(*) from Users)*100, 2) as percentage from Register r inner join Users u on r.user_id = u.user_id group by contest_id ORDER BY percentage DESC, r.contest_id ASC;