SELECT E.EmpFname, E.EmpLname, P.EmpPosition 
FROM EmployeeInfo E INNER JOIN EmployeePosition P ON
E.EmpID = P.EmpID AND P.EmpPosition IN ('Manager');