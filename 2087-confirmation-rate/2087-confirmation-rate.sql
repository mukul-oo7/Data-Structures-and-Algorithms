# Write your MySQL query statement below

SELECT sign.user_id, IFNULL(conf.confirmation_rate, 0) as confirmation_rate
FROM Signups sign LEFT JOIN (
    SELECT user_id, Round(AVG(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END), 2) AS confirmation_rate
    FROM Confirmations
    GROUP BY user_id
) AS conf
ON sign.user_id = conf.user_id;
