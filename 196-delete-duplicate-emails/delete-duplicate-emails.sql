# Write your MySQL query statement below

/*For SQL users, please note that you are supposed to write a DELETE statement and not a SELECT one*/


DELETE p1
FROM Person p1
INNER JOIN Person p2
WHERE p1.email = p2.email
AND
p1.id > p2.id