-- Title: Customers Who Never Order
-- Description:
--     Write an SQL query to report all customers who never order anything.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/customers-who-never-order/

-- Write your MySQL query statement below
SELECT name as Customers FROM Customers
WHERE NOT EXISTS (
    SELECT * FROM Orders
    WHERE Orders.customerId = Customers.id
)
