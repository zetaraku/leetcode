-- Title: Duplicate Emails
-- Description:
--     Write an SQL query to report all the duplicate emails.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/duplicate-emails/

-- Write your MySQL query statement below
SELECT email AS Email
FROM Person
GROUP BY email
HAVING COUNT(*) > 1
