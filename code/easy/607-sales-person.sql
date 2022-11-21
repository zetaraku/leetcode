-- Title: Sales Person
-- Description:
--     Write an SQL query to report the names of all the salespersons who did not have any orders related to the company with the name "RED".
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/sales-person/

-- Write your PL/SQL query statement below
SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (
    SELECT DISTINCT sales_id
    FROM Orders LEFT JOIN Company USING (com_id)
    WHERE Company.name = 'RED'
)
