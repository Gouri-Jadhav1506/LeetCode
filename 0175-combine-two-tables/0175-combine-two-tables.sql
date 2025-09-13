# Write your MySQL query statement below
SELECT 
    g.firstName,
    g.lastName,
    a.city,
    a.state
FROM Person g
LEFT JOIN Address a
    ON g.personId = a.personId;
