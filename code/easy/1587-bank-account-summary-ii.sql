-- Title: Bank Account Summary II
-- Description:
--     Write an SQL query to report the name and balance of users with a balance higher than 10000.
--     The balance of an account is equal to the sum of the amounts of all transactions involving that account.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/bank-account-summary-ii/

-- Write your MySQL query statement below
SELECT
    name,
    SUM(amount) AS balance
FROM Users LEFT JOIN Transactions USING (account)
GROUP BY account
HAVING balance > 10000
