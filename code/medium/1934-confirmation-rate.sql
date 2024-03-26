-- Title: Confirmation Rate
-- Description:
--     The confirmation rate of a user is the number of 'confirmed' messages divided by the total number of requested confirmation messages.
--     The confirmation rate of a user that did not request any confirmation messages is 0.
--     Round the confirmation rate to two decimal places.
--     Write a solution to find the confirmation rate of each user.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/confirmation-rate/

-- Write your PostgreSQL query statement below
SELECT
    user_id,
    CASE
        WHEN requested_count IS NULL THEN 0
        ELSE ROUND(1.0 * confirmed_count / requested_count, 2)
    END AS confirmation_rate
FROM Signups
    LEFT JOIN (
        SELECT
            user_id,
            COUNT(CASE action WHEN 'confirmed' THEN TRUE END) AS confirmed_count,
            COUNT(*) AS requested_count
        FROM Confirmations
        GROUP BY user_id
    ) USING (user_id)
