-- SELECT student_id, subject_name, count(*) from Examinations GROUP BY student_id, subject_name;

-- SELECT * from Students CROSS JOIN Subjects;

SELECT courses.student_id, courses.student_name, courses.subject_name, IFNULL(attended_exams, 0) As attended_exams
FROM (
    SELECT * 
    from Students 
    CROSS JOIN Subjects
) As courses 
left join (
    SELECT student_id, subject_name, count(*) As attended_exams
    from Examinations 
    GROUP BY student_id, subject_name
) Attended_exams ON courses.student_id = Attended_exams.student_id and courses.subject_name = Attended_exams.subject_name ORDER BY student_id ASC, subject_name ASC;