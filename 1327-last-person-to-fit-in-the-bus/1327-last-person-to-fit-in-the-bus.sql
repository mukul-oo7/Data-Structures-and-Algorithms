# Write your MySQL query statement below

SELECT person_name
FROM (
    SELECT person_name, sum(weight) OVER (ORDER BY turn) as cumutative_weight
    FROM Queue
) As oq
WHERE cumutative_weight<=1000
ORDER BY cumutative_weight DESC
LIMIT 1;