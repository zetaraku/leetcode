-- Title: Rising Temperature
-- Description:
--     Write an SQL query to find all dates' Id with higher temperatures compared to its previous dates (yesterday).
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/rising-temperature/

-- Write your PostgreSQL query statement below
SELECT w.id
FROM Weather w LEFT JOIN Weather w_prev
    ON w.recordDate - INTERVAL '1 DAY' = w_prev.recordDate
WHERE w.temperature > w_prev.temperature
