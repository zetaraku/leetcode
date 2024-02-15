-- Title: Replace Employee ID With The Unique Identifier
-- Description:
--     Write a solution to show the unique ID of each user, If a user does not have a unique ID replace just show null.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/

-- Write your PostgreSQL query statement below
SELECT name, unique_id
FROM Employees LEFT JOIN EmployeeUNI USING (id)
