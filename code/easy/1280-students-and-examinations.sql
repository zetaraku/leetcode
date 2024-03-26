-- Title: Students and Examinations
-- Description:
--     Write a solution to find the number of times each student attended each exam.
--     Return the result table ordered by student_id and subject_name.
-- Link: https://leetcode.com/problems/students-and-examinations/

-- Write your PostgreSQL query statement below
SELECT
    student_id, student_name, subject_name,
    COALESCE(attended_exams, 0) AS attended_exams
FROM Students CROSS JOIN Subjects
    LEFT JOIN (
        SELECT
            student_id, subject_name,
            COUNT(*) AS attended_exams
        FROM Examinations
        GROUP BY student_id, subject_name
    ) USING (student_id, subject_name)
ORDER BY student_id, subject_name
