# Write your MySQL query statement below

# JOINING with the help of JOIN 

SELECT d.name AS Department,
e.name AS Employee,
e.salary AS Salary

FROM Employee e
INNER JOIN Department d
ON e.departmentId = d.id

# Condition as Sub query
WHERE  3 > (

    SELECT COUNT(DISTINCT (e2.salary))
    FROM Employee e2
    WHERE e2.salary > e.salary
    AND
    e.departmentID  = e2.departmentID  

)


/*
WHERE  3 > (query) -> filter outs the part who do have have higher salary within the same department

Short Note 📝
Concept: Top 3 salaries in each department
Subquery counts distinct salaries greater than current salary
If count is less than 3, current employee is in top 3
DISTINCT is important to handle salary ties

Same department comparison:

e.departmentId = e2.departmentId

Memory trick:

Count higher distinct salaries < 3 = top 3 employee

*/