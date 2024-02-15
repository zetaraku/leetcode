-- Title: Customer Who Visited but Did Not Make Any Transactions
-- Description:
--     Write an SQL query to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits.
--     Return the result table sorted in any order.
-- Link: https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/

-- Write your PostgreSQL query statement below
SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits LEFT JOIN Transactions USING (visit_id)
WHERE transaction_id IS NULL
GROUP BY customer_id
