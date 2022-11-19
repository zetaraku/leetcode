-- Title: Second Highest Salary
-- Description:
--     Write an SQL query to report the second highest salary from the Employee table.
--     If there is no second highest salary, the query should report null.
-- Link: https://leetcode.com/problems/second-highest-salary/

-- Write your MySQL query statement below
SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary
