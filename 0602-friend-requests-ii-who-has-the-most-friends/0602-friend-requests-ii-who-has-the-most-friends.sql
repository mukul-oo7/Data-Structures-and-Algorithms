# Write your MySQL query statement below



-- SELECT ra2.requester_id AS id, (COUNT(*)+(SELECT COUNT(*) FROM RequestAccepted ra1 WHERE ra1.accepter_id = ra2.requester_id)) AS num
-- FROM RequestAccepted AS ra2
-- GROUP BY requester_id
-- ORDER BY num DESC
-- LIMIT 1;



SELECT id, sum(num) AS num
FROM (
    SELECT requester_id AS id, count(*) AS num
    FROM RequestAccepted
    GROUP BY requester_id

    UNION ALL

    SELECT accepter_id AS id, count(*) AS num
    FROM RequestAccepted
    GROUP BY accepter_id
) AS frnds
GROUP BY id
ORDER BY num DESC
LIMIT 1;