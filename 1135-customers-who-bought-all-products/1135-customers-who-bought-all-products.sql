# Write your MySQL query statement below


SELECT customer_id
FROM ( SELECT DISTINCT customer_id, product_key FROM Customer ) AS unique_customer
GROUP BY customer_id
HAVING count(*) = ( SELECT count(*) FROM Product);