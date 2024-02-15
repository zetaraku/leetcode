-- Title: Find Customer Referee
-- Description:
--     Write an SQL query to report the names of the customer that are not referred by the customer with id = 2.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/find-customer-referee/

-- Write your PostgreSQL query statement below
SELECT name FROM Customer
WHERE referee_id <> 2 OR referee_id IS NULL
