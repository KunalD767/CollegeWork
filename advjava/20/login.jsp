<%@ page import="java.sql.*" %>
<html>
<head><title>Sign Up</title></head>
<body>
<h2>Login</h2>
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
            PreparedStatement ps = conn.prepareStatement("SELECT * FROM users WHERE username = ? AND password = ?");
            ps.setString(1, uname);
            ps.setString(2, pass); // Note: hash password in real apps
            ResultSet rs = ps.executeQuery();
            if (rs.next()) {
                out.println("<p style='color:green;'>Login successful. Welcome, " + uname + "!</p>");
            } else {
                out.println("<p style='color:red;'>Invalid credentials. Please try again.</p>");
            }
            rs.close(); ps.close(); conn.close();
        } catch (Exception e) {
            out.println("<p style='color:red;'>Error: " + e.getMessage() + "</p>");
        }
    }
%>
</body>
</html>
