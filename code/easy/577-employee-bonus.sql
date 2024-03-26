-- Title: Employee Bonus
-- Description:
--     Write a solution to report the name and bonus amount of each employee with a bonus less than 1000.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/employee-bonus/

-- Write your PostgreSQL query statement below
SELECT name, bonus
FROM Employee LEFT JOIN Bonus USING (empId)
WHERE COALESCE(bonus, 0) < 1000
