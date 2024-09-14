# Write your MySQL query statement below

SELECT 
    activity_date as day, 
    count(DISTINCT user_id) as active_users 
FROM 
    Activity 
GROUP BY 
    activity_date
HAVING 
    activity_date BETWEEN '2019-06-28' AND '2019-07-27' 
ORDER BY
    day ASC;