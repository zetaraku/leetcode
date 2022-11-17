-- Title: Delete Duplicate Emails
-- Description:
--     Write an SQL query to delete all the duplicate emails, keeping only one unique email with the smallest id.
--     Note that you are supposed to write a DELETE statement and not a SELECT one.
--     After running your script, the answer shown is the Person table.
--     The driver will first compile and run your piece of code and then show the Person table.
--     The final order of the Person table does not matter.
-- Link: https://leetcode.com/problems/delete-duplicate-emails/

-- Write your MySQL query statement below
DELETE FROM Person
WHERE id NOT IN (
    -- We need this extra SELECT to fix the "You can't specify target table 'Person' for update in FROM clause" error
    SELECT * FROM (
        SELECT MIN(id) FROM Person
        GROUP BY email
    ) AS tmp
)
