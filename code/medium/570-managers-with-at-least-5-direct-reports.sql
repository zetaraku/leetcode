-- Title: Managers with at Least 5 Direct Reports
-- Description:
--     Write a solution to find managers with at least five direct reports.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/managers-with-at-least-5-direct-reports/

-- Write your PostgreSQL query statement below
SELECT name FROM Employee
WHERE id IN (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*) >= 5
)
