# Write your MySQL query statement below
SELECT e1.employee_id, e1.name, count(*) AS reports_count, ROUND(AVG(e2.age), 0) AS average_age
FROM Employees As e1 join Employees As e2
ON e1.employee_id = e2.reports_to
GROUP BY e1.employee_id
ORDER BY e1.employee_id;