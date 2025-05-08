<!DOCTYPE html>
<html>
<head>
    <title>Employee Registration Form</title>
</head>
<body>
    <h2>Employee Registration</h2>
    <form action="EmployeeServlet" method="post">
        First Name: <input type="text" name="first_name" required><br><br>
        Last Name: <input type="text" name="last_name" required><br><br>
        Email: <input type="email" name="email" required><br><br>
        Phone: <input type="text" name="phone" required><br><br>
        Department: <input type="text" name="department" required><br><br>
        <input type="submit" value="Register">
    </form>
    <br>
    <a href="employeeList.jsp">View Registered Employees</a>
</body>
</html>