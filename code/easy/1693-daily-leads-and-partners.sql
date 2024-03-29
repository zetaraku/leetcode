-- Title: Daily Leads and Partners
-- Description:
--     Write an SQL query that will, for each date_id and make_name, return the number of distinct lead_id's and distinct partner_id's.
--     Return the result table in any order.
-- Link: https://leetcode.com/problems/daily-leads-and-partners/

-- Write your MySQL query statement below
SELECT
    date_id,
    make_name,
    COUNT(DISTINCT lead_id) AS unique_leads,
    COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY date_id, make_name
