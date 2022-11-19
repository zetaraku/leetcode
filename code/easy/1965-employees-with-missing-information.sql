-- Title: Employees With Missing Information
-- Description:
--     Write an SQL query to report the IDs of all the employees with missing information. The information of an employee is missing if:
--         - The employee's name is missing, or
--         - The employee's salary is missing.
--     Return the result table ordered by employee_id in ascending order.
-- Link: https://leetcode.com/problems/employees-with-missing-information/

-- Write your PL/SQL query statement below
SELECT employee_id
FROM Employees FULL JOIN Salaries USING (employee_id)
WHERE (name IS NULL) OR (salary IS NULL)
ORDER BY employee_id
