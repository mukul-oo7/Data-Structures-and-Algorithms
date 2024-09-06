# Write your MySQL query statement below
-- SELECT managerID, count(*) FROM Employee GROUP BY managerId Having count(*) >= 5; 

SELECT name FROM Employee WHERE id in (SELECT managerID FROM Employee GROUP BY managerId Having count(*) >= 5);