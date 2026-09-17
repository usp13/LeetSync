# Write your MySQL query statement below

SELECT score,
    (
        SELECT COUNT(DISTINCT s2.Score)
        FROM Scores AS s2
        WHERE s2.Score >= s.Score
    ) AS `rank`
FROM Scores AS s
ORDER BY Score DESC;