-- Title: Group Sold Products By The Date
-- Description:
--     Write an SQL query to find for each date the number of different products sold and their names.
--     The sold products names for each date should be sorted lexicographically.
--     Return the result table ordered by sell_date.
-- Link: https://leetcode.com/problems/group-sold-products-by-the-date/

-- Write your MySQL query statement below
SELECT
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product SEPARATOR ',') AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date
