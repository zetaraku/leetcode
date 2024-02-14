-- Title: Invalid Tweets
-- Description:
--     Write a solution to find the IDs of the invalid tweets.
--     The tweet is invalid if the number of characters used in the content of the tweet is strictly greater than 15.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/invalid-tweets/

-- Write your PostgreSQL query statement below
SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15
