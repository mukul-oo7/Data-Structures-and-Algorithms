# Write your MySQL query statement below

SELECT employee_id
FROM Employees e
WHERE manager_id IS NOT null 
    AND salary < 30000
    AND manager_id NOT IN (
        SELECT employee_id
        FROM Employees
    )
ORDER BY employee_id;