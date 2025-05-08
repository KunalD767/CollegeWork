import java.io.*;
import java.net.*;

public class TCPServer{
    public static void main(String[] args) {
        int port = 5050; // Changed port to 5050

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server is listening on port " + port);

            while (true) {
                try (Socket socket = serverSocket.accept();
                     BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                     PrintWriter output = new PrintWriter(socket.getOutputStream(), true)) {

                    System.out.println("New client connected");

                    // Read number from client
                    String received = input.readLine();
                    if (received == null) {
                        System.out.println("Client disconnected.");
                        continue;
                    }

                    int number = Integer.parseInt(received);
                    System.out.println("Received number: " + number);

                    // Calculate factorial
                    long factorial = calculateFactorial(number);

                    // Send result back to client
                    output.println(factorial);
                } catch (IOException | NumberFormatException e) {
                    System.out.println("Error handling client: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println("Server error: " + e.getMessage());
        }
    }

    // Method to calculate factorial
    private static long calculateFactorial(int n) {
        if (n < 0) return -1; // Return -1 for invalid inputs
        long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
}
