-- Title: Swap Salary
-- Description:
--     Write an SQL query to swap all 'f' and 'm' values (i.e., change all 'f' values to 'm' and vice versa) with a single update statement and no intermediate temporary tables.
--     Note that you must write a single update statement, do not write any select statement for this problem.
-- Link: https://leetcode.com/problems/swap-salary/

-- Write your MySQL query statement below
UPDATE Salary
SET
    sex = CASE sex
        WHEN 'f' THEN 'm'
        WHEN 'm' THEN 'f'
    END
