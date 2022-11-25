-- Title: Actors and Directors Who Cooperated At Least Three Times
-- Description:
--     Write a SQL query for a report that provides the pairs (actor_id, director_id) where the actor has cooperated with the director at least three times.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/

-- Write your MySQL query statement below
SELECT actor_id, director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(*) >= 3
