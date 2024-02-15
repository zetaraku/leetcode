-- Title: Product Sales Analysis I
-- Description:
--     Write a solution to report the product_name, year, and price for each sale_id in the Sales table.
--     Return the resulting table in any order.
-- Link: https://leetcode.com/problems/product-sales-analysis-i/

-- Write your PostgreSQL query statement below
SELECT product_name, year, price
FROM Sales JOIN Product USING (product_id)
