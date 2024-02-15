-- Title: Article Views I
-- Description:
--     Write an SQL query to find all the authors that viewed at least one of their own articles.
--     Return the result table sorted by id in ascending order.
-- Link: https://leetcode.com/problems/article-views-i/

-- Write your PostgreSQL query statement below
SELECT DISTINCT viewer_id AS id FROM Views
WHERE viewer_id = author_id
ORDER BY id ASC
