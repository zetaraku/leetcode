-- Title: User Activity for the Past 30 Days I
-- Description:
--     Write an SQL query to find the daily active user count for a period of 30 days ending 2019-07-27 inclusively.
--     A user was active on someday if they made at least one activity on that day.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/user-activity-for-the-past-30-days-i/

-- Write your MySQL query statement below
SELECT
    activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE DATEDIFF('2019-07-27', activity_date) BETWEEN 0 AND 29
GROUP BY activity_date
