-- Title: Rising Temperature
-- Description:
--     Write an SQL query to find all dates' Id with higher temperatures compared to its previous dates (yesterday).
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/rising-temperature/

-- Write your PL/SQL query statement below
SELECT w1.id
FROM Weather w1 LEFT JOIN Weather w2
    ON w1.recordDate - INTERVAL '1' DAY = w2.recordDate
WHERE w1.temperature > w2.temperature
