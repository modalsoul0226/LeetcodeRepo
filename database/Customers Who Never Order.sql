# Write your MySQL query statement below
SELECT Customers.Name as Customers
FROM Customers
WHERE Customers.Id not in 

(SELECT c.Id
FROM Customers c JOIN Orders o
WHERE c.Id = o.CustomerId);