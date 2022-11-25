-- Title: Sales Analysis III
-- Description:
--     Write an SQL query that reports the products that were only sold in the first quarter of 2019.
--     That is, between 2019-01-01 and 2019-03-31 inclusive.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/sales-analysis-iii/

-- Write your MySQL query statement below
SELECT product_id, product_name
FROM Product
WHERE product_id IN (
    SELECT DISTINCT product_id
    FROM Sales
    WHERE sale_date BETWEEN '2019-01-01' AND '2019-03-31'
) AND product_id NOT IN (
    SELECT DISTINCT product_id
    FROM Sales
    WHERE sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31'
)
