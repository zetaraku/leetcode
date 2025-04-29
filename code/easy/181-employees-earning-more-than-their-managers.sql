-- Title: Employees Earning More Than Their Managers
-- Description:
--     Write a solution to find the employees who earn more than their managers.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/employees-earning-more-than-their-managers/

-- Write your PostgreSQL query statement below
SELECT e.name AS Employee
FROM Employee AS e INNER JOIN Employee AS m ON e.managerId = m.id
WHERE e.salary > m.salary
