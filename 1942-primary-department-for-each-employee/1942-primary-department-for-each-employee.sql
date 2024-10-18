# Write your MySQL query statement below

-- SELECT employee_id, department_id 
-- FROM Employee
-- WHERE (employee_id, department_id) IN ( 
--     SELECT employee_id, department_id 
--     FROM Employee 
--     GROUP BY employee_id 
--     HAVING count(*) = 1
-- )
-- OR primary_flag = 'Y';


SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'

UNION

SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING count(*)=1;