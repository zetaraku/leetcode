-- Title: Find Followers Count
-- Description:
--     Write an SQL query that will, for each user, return the number of followers.
--     Return the result table ordered by user_id.
-- Link: https://leetcode.com/problems/find-followers-count/

-- Write your MySQL query statement below
SELECT
    user_id,
    COUNT(*) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id ASC
