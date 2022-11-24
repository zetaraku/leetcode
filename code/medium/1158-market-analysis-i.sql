-- Title: Market Analysis I
-- Description:
--     Write an SQL query to find for each user, the join date and the number of orders they made as a buyer in 2019.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/market-analysis-i/

-- Write your MySQL query statement below
SELECT
    user_id AS buyer_id,
    join_date,
    COUNT(IF(YEAR(order_date) = 2019, TRUE, NULL)) AS orders_in_2019
FROM Users LEFT JOIN Orders ON user_id = buyer_id
GROUP BY user_id
