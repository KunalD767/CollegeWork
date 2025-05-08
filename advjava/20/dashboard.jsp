<%@ page import="java.sql.*" %>
<html>
<head><title>Sign Up</title></head>
<body>
<h2>Sign Up</h2>
<form method="post">
    Username: <input type="text" name="username" required /><br>
    Password: <input type="password" name="password" required /><br>
    <input type="submit" value="Register" />
</form>
<%
    if (request.getMethod().equalsIgnoreCase("POST")) {
        String uname = request.getParameter("username");
        String pass = request.getParameter("password");

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/jspauth?useSSL=false&serverTimezone=UTC&allowPublicKeyRetrieval=true", "root", "Kunal@123");
            PreparedStatement ps = conn.prepareStatement("INSERT INTO users (username, password) VALUES (?, ?)");
            ps.setString(1, uname);
            ps.setString(2, pass); // Note: hash password in real apps
            int result = ps.executeUpdate();
            if (result > 0) {
                out.println("<p style='color:green;'>Registration successful. <a href='login.jsp'>Login Now</a></p>");
            }
            ps.close(); conn.close();
        } catch (Exception e) {
            out.println("<p style='color:red;'>Error: " + e.getMessage() + "</p>");
        }
    }
%>
</body>
</html>
