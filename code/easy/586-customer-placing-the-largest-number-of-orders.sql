-- Title: Customer Placing the Largest Number of Orders
-- Description:
--     Write an SQL query to find the customer_number for the customer who has placed the largest number of orders.
--     The test cases are generated so that exactly one customer will have placed more orders than any other customer.
--     Follow up: What if more than one customer has the largest number of orders, can you find all the customer_number in this case?
-- Link: https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/

-- Write your MySQL query statement below
SELECT customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(*) = (
    SELECT MAX(count.val) FROM (
        SELECT COUNT(*) AS val
        FROM Orders
        GROUP BY customer_number
    ) AS count
)
