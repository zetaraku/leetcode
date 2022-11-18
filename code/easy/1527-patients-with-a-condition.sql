-- Title: Patients With a Condition
-- Description:
--     Write an SQL query to report the patient_id, patient_name and conditions of patients who have Type I Diabetes.
--     Type I Diabetes always starts with DIAB1 prefix.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/patients-with-a-condition/

-- Write your MySQL query statement below
SELECT patient_id, patient_name, conditions
FROM Patients
WHERE conditions REGEXP '\\bDIAB1'
