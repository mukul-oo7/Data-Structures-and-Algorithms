# Write your MySQL query statement below

(
    SELECT u.name AS results
    FROM MovieRating m 
    JOIN Users u
    ON m.user_id = u.user_id
    Group by m.user_id
    ORDER BY count(*) DESC,u.name ASC
    LIMIT 1
)
UNION ALL
(
    SELECT m.title
    FROM MovieRating mr 
    JOIN Movies m
    ON mr.movie_id = m.movie_id
    WHERE MONTH(mr.created_at) = 2 AND YEAR(mr.created_at) = 2020
    GROUP BY m.movie_id
    ORDER BY AVG(mr.rating) DESC, m.title
    LIMIT 1
);