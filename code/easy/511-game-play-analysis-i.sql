-- Title: Game Play Analysis I
-- Description:
--     Write an SQL query to report the first login date for each player.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/game-play-analysis-i/

-- Write your MySQL query statement below
SELECT
    player_id,
    MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id
