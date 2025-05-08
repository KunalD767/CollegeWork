<%@ page language="java" contentType="text/html; charset=UTF-8" %>
<%@ page import="oddapp.OddEvenRunner" %>
<html>
<head>
    <title>Result</title>
</head>
<body>
<%
    try {
        int ocount = Integer.parseInt(request.getParameter("odd"));
        int ecount = Integer.parseInt(request.getParameter("even"));

        OddEvenRunner runner = new OddEvenRunner(ocount, ecount);
        String output = runner.runThreads();

        out.println("<h3>Output:</h3>");
        out.println("<pre>" + output + "</pre>");
    } catch (Exception e) {
        out.println("<p style='color:red;'>Error: " + e.getMessage() + "</p>");
    }
%>
</body>
</html>