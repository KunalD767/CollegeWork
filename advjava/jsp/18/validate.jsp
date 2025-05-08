<%@ page import="java.util.regex.*" %>
<%
    // Get the form data
    String name = request.getParameter("name");
    String email = request.getParameter("email");
    String password = request.getParameter("password");

    // Flags to track if input is valid
    boolean isValid = true;
    String errorMessage = "";
    if (name == null || name.trim().isEmpty()) {
        isValid = false;
        errorMessage += "Name is required.<br>";
    }
    if (email == null || email.trim().isEmpty()) {
        isValid = false;
        errorMessage += "Email is required.<br>";
    } else {
        String emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";
        Pattern pattern = Pattern.compile(emailRegex);
        Matcher matcher = pattern.matcher(email);
        if (!matcher.matches()) {
            isValid = false;
            errorMessage += "Invalid email format.<br>";
        }
    }
    if (password == null || password.trim().isEmpty()) {
        isValid = false;
        errorMessage += "Password is required.<br>";
    } else if (password.length() < 6) {
        isValid = false;
        errorMessage += "Password must be at least 6 characters long.<br>";
    }
    if (isValid) {
        out.println("<h3>Registration successful!</h3>");
        out.println("<p>Name: " + name + "</p>");
        out.println("<p>Email: " + email + "</p>");
        out.println("<p>Password: " + password + "</p>");
    } else {
        out.println("<h3>Form Submission Failed!</h3>");
        out.println("<p>Please fix the following errors:</p>");
        out.println("<div style='color: red;'>" + errorMessage + "</div>");
        out.println("<br><a href='form.html'>Go back</a>");
    }
%>
