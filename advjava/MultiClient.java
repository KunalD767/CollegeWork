import java.io.*;
import java.net.*;
import java.util.Scanner;

public class MultiClient {
    public static void main(String[] args) {
        String serverAddress = "localhost"; // Server IP
        int port = 5010; // Server port

        try (Socket socket = new Socket(serverAddress, port);
             BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
             Scanner scanner = new Scanner(System.in)) {

            System.out.print("Enter a number to find its factorial: ");
            int number = scanner.nextInt();

            // Send number to server
            output.println(number);

            // Receive response from server
            String response = input.readLine();
            if (response != null) {
                System.out.println("Factorial of " + number + " is: " + response);
            } else {
                System.out.println("No response from server.");
            }
        } catch (IOException e) {
            System.out.println("Client error: " + e.getMessage());
        }
    }
}
