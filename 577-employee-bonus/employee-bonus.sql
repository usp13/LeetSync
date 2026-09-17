

SELECT e.name AS name , b.bonus as bonus
FROM Employee e
LEFT JOIN Bonus b  
ON e.empId = b.empID
WHERE b.bonus IS NULL OR b.bonus < 1000 ;