-- Title: Capital Gain/Loss
-- Description:
--     Write an SQL query to report the Capital gain/loss for each stock.
--     The Capital gain/loss of a stock is the total gain or loss after buying and selling the stock one or many times.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/capital-gainloss/

-- Write your MySQL query statement below
SELECT
    stock_name,
    SUM(
        CASE operation
            WHEN 'Buy' THEN
                - price
            WHEN 'Sell' THEN
                + price
        END
    ) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name
