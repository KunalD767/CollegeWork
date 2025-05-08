import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class SetCookieServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        Cookie cookie = new Cookie("username", "KunalDua");

        cookie.setMaxAge(60 * 60 * 24); // 24 hours

        response.addCookie(cookie);

        out.println("<html><body>");
        out.println("<h2>Cookie has been set successfully!</h2>");
        out.println("<p>Cookie Name: username</p>");
        out.println("<p>Cookie Value: KunalDua</p>");
        out.println("</body></html>");
        
        out.close();
    }
}
