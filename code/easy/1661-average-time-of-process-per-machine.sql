-- Title: Average Time of Process per Machine
-- Description:
--     There is a factory website that has several machines each running the same number of processes.
--     Write a solution to find the average time each machine takes to complete a process.
--     The time to complete a process is the 'end' timestamp minus the 'start' timestamp.
--     The average time is calculated by the total time to complete every process on the machine divided by the number of processes that were run.
--     The resulting table should have the machine_id along with the average time as processing_time, which should be rounded to 3 decimal places.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/average-time-of-process-per-machine/

-- Write your PostgreSQL query statement below
SELECT
    machine_id,
    ROUND(CAST(AVG("end".timestamp - "start".timestamp) AS NUMERIC), 3) AS processing_time
FROM
    (SELECT * FROM Activity WHERE activity_type = 'start') AS "start"
    JOIN
    (SELECT * FROM Activity WHERE activity_type = 'end') AS "end"
    USING (machine_id, process_id)
GROUP BY machine_id
