# Write your MySQL query statement below

-- SELECT c1.visited_on, sum(c2.amount)
-- FROM Customer c1
-- CROSS JOIN Customer c2
-- WHERE c2.visited_on <= c1.visited_on AND c2.visited_on >= DATE_SUB(c1.visited_on, INTERVAL 6 DAY)
-- GROUP BY c1.visited_on
-- ORDER BY c1.visited_on;

SELECT DISTINCT c1.visited_on, 
    (SELECT SUM(amount) FROM Customer c2 WHERE c2.visited_on<=c1.visited_on AND c2.visited_on >= DATE_SUB(c1.visited_on, INTERVAL 6 DAY)) AS amount,
    ROUND((SELECT SUM(amount)/7 FROM Customer c2 WHERE c2.visited_on<=c1.visited_on AND c2.visited_on >= DATE_SUB(c1.visited_on, INTERVAL 6 DAY)), 2) AS average_amount
    
FROM Customer c1
WHERE DATE_SUB(visited_on, INTERVAL 6 DAY) IN (
    SELECT DISTINCT visited_on 
    FROM Customer
);