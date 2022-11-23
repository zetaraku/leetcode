-- Title: The Latest Login in 2020
-- Description:
--     Write an SQL query to report the latest login for all users in the year 2020.
--     Do not include the users who did not login in 2020.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/the-latest-login-in-2020/

-- Write your MySQL query statement below
SELECT
    user_id,
    MAX(time_stamp) AS last_stamp
FROM Logins
WHERE YEAR(time_stamp) = 2020
GROUP BY user_id
