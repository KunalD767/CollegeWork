<%@ page import="java.sql.*" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Insert User</title>
</head>
<body>
<%
    String name = request.getParameter("name");
    String email = request.getParameter("email");

    // Simple null checks for safety
    if (name == null || email == null || name.isEmpty() || email.isEmpty()) {
        out.println("<h3>Error: Name and email must not be empty.</h3>");
    } else {
        // DB credentials
        String url = "jdbc:mysql://localhost:3306/student?useSSL=false&serverTimezone=UTC&allowPublicKeyRetrieval=true";
        String dbUsername = "root";
        String dbPassword = "Kunal@123"; 
        Connection conn = null;
        PreparedStatement stmt = null;

        try {
            // Load JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");
            out.println("Driver loaded successfully.<br>");

            // Connect to database
            conn = DriverManager.getConnection(url, dbUsername, dbPassword);

            // Insert query
            String sql = "INSERT INTO students (name, email) VALUES (?, ?)";
            stmt = conn.prepareStatement(sql);
            stmt.setString(1, name);
            stmt.setString(2, email);

            int rows = stmt.executeUpdate();

            if (rows > 0) {
                out.println("<h3>Data inserted successfully!</h3>");
            } else {
                out.println("<h3>Failed to insert data.</h3>");
            }

        } catch (Exception e) {
            out.println("<h3>Error: " + e.getMessage() + "</h3>");
            e.printStackTrace(new java.io.PrintWriter(out));
        } finally {
            try { if (stmt != null) stmt.close(); } catch (Exception e) {}
            try { if (conn != null) conn.close(); } catch (Exception e) {}
        }
    }
%>
</body>
</html>
