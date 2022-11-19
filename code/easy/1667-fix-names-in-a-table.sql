-- Title: Fix Names in a Table
-- Description:
--     Write an SQL query to fix the names so that only the first character is uppercase and the rest are lowercase.
--     Return the result table ordered by user_id.
-- Link: https://leetcode.com/problems/fix-names-in-a-table/

-- Write your PL/SQL query statement below
SELECT
    user_id,
    INITCAP(name) AS name
FROM Users
ORDER BY user_id
