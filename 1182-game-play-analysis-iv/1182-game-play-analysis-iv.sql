# Write your MySQL query statement below

SELECT ROUND(COUNT(*)/(SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM Activity a1
WHERE (player_id, DATE_SUB(event_date, INTERVAL 1 DAY))
IN (
    SELECT player_id, MIN(event_date)
    FROM Activity
    GROUP BY player_id
);

-- SELECT ROUND(COUNT(DISTINCT a1.player_id)/(SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
-- FROM Activity a1 JOIN Activity a2
-- ON a1.player_id = a2.player_id
-- AND a2.event_date = DATE_ADD(a1.event_date, INTERVAL 1 DAY);
