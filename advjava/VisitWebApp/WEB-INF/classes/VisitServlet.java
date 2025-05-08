import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class VisitServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        boolean isReturningVisitor = false;
        int visitCount = 0;

        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals("visitCount")) {
                    isReturningVisitor = true;
                    visitCount = Integer.parseInt(cookie.getValue());
                    break;
                }
            }
        }

        if (isReturningVisitor) {
            visitCount++;
            out.println("<h2>Welcome Back</h2>");
            out.println("<p>You have visited " + visitCount + " times.</p>");
        } else {
            visitCount = 1;
            out.println("<h2>Welcome, you are visiting for the first time</h2>");
        }
        Cookie newCookie = new Cookie("visitCount", String.valueOf(visitCount));
        newCookie.setMaxAge(60 * 60 * 24 * 365);
        response.addCookie(newCookie);

        out.close();
    }
}