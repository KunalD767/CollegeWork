<%@ page import="java.sql.*" %>
<%
    String name = request.getParameter("name");
    String email = request.getParameter("email");

    String url = "jdbc:mysql://127.0.0.1:3306/jspdemo?useSSL=false&serverTimezone=UTC&allowPublicKeyRetrieval=true";
    String username = "root";
    String password = "Kunal@123";

    Connection conn = null;
    PreparedStatement stmt = null;

    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
        conn = DriverManager.getConnection(url, username, password);

        String sql = "INSERT INTO students (name, email) VALUES (?, ?)";
        stmt = conn.prepareStatement(sql);
        stmt.setString(1, name);
        stmt.setString(2, email);

        int result = stmt.executeUpdate();

        if (result > 0) {
            out.println("<h3>Data inserted successfully!</h3>");
        } else {
            out.println("<h3>Insertion failed!</h3>");
        }
    } catch (Exception e) {
        out.println("Error: " + e.getMessage());
    } finally {
        if (stmt != null) stmt.close();
        if (conn != null) conn.close();
    }
%>
<a href="form.html">Go Back</a>
