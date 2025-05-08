import java.io.*;
import java.net.*;

public class MultiClientServer {
    public static void main(String[] args) {
        int port = 5010; // Server port

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server is listening on port " + port);

            while (true) {
                // Accept a new client connection
                Socket clientSocket = serverSocket.accept();
                System.out.println("New client connected: " + clientSocket.getInetAddress());

                // Handle the client in a separate thread
                new ClientHandler(clientSocket).start();
            }
        } catch (IOException e) {
            System.out.println("Server error: " + e.getMessage());
        }
    }
}

// Thread to handle each client separately
class ClientHandler extends Thread {
    private final Socket clientSocket;

    public ClientHandler(Socket socket) {
        this.clientSocket = socket;
    }

    @Override
    public void run() {
        try (BufferedReader input = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
             PrintWriter output = new PrintWriter(clientSocket.getOutputStream(), true)) {

            // Read number from client
            String received = input.readLine();
            if (received == null) {
                System.out.println("Client disconnected.");
                return;
            }

            int number = Integer.parseInt(received);
            System.out.println("Received number from client: " + number);

            // Calculate factorial
            long factorial = calculateFactorial(number);

            // Send response to client
            output.println(factorial);

        } catch (IOException | NumberFormatException e) {
            System.out.println("Error handling client: " + e.getMessage());
        } finally {
            try {
                clientSocket.close();
            } catch (IOException e) {
                System.out.println("Error closing client socket: " + e.getMessage());
            }
        }
    }

    // Method to calculate factorial
    private static long calculateFactorial(int n) {
        if (n < 0) return -1; // Invalid input
        long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
}

