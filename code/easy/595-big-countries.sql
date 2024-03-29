-- Title: Big Countries
-- Description:
--     A country is big if it has an area of bigger than 3 million square km or a population of more than 25 million.
--     Write a SQL solution to output big countries' name, population and area.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/big-countries/

-- Write your PostgreSQL query statement below
SELECT name, population, area FROM World
WHERE area >= 3000000 OR population >= 25000000
