# Write your MySQL query statement below
SELECT e1.Name AS Employee
FROM Employee AS e1 JOIN Employee AS e2
WHERE e1.ManagerId = e2.Id and e1.Salary > e2.Salary