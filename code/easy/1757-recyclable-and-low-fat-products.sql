-- Title: Recyclable and Low Fat Products
-- Description:
--     Write an SQL query to find the ids of products that are both low fat and recyclable.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/recyclable-and-low-fat-products/

-- Write your MySQL query statement below
SELECT product_id FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y'
