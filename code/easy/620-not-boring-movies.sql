-- Title: Not Boring Movies
-- Description:
--     Write a solution to report the movies with an odd-numbered ID and a description that is not "boring".
--     Return the result table ordered by rating in descending order.
-- Link: https://leetcode.com/problems/not-boring-movies/

-- Write your PostgreSQL query statement below
SELECT * FROM Cinema
WHERE MOD(id, 2) <> 0 AND description <> 'boring'
ORDER BY rating DESC
