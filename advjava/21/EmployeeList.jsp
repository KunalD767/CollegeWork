<%@ page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
    <title>Registered Employees</title>
</head>
<body>
    <h2>Registered Employees</h2>
    <table border="1">
        <tr>
            <th>ID</th><th>First Name</th><th>Last Name</th><th>Email</th><th>Phone</th><th>Department</th>
        </tr>
        <%
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                Connection conn = DriverManager.getConnection(
                    "jdbc:mysql://127.0.0.1:3306/jspauth?useSSL=false&serverTimezone=UTC&allowPublicKeyRetrieval=true",
                    "root", "Kunal@123"
                );
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery("SELECT * FROM employees");
                while (rs.next()) {
        %>
        <tr>
            <td><%= rs.getInt("id") %></td>
            <td><%= rs.getString("first_name") %></td>
            <td><%= rs.getString("last_name") %></td>
            <td><%= rs.getString("email") %></td>
            <td><%= rs.getString("phone") %></td>
            <td><%= rs.getString("department") %></td>
        </tr>
        <%
                }
                rs.close();
                stmt.close();
                conn.close();
            } catch (Exception e) {
                out.println("<tr><td colspan='6' style='color:red;'>Error: " + e.getMessage() + "</td></tr>");
            }
        %>
    </table>
    <br>
    <a href="employee.jsp">Add New Employee</a>
</body>
</html>