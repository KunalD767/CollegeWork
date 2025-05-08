import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPServer {
    public static void main(String[] args) {
        int port = 5060; // Server Port
        try (DatagramSocket socket = new DatagramSocket(port)) {
            System.out.println("UDP Server is running on port " + port + "...");

            while (true) {
                // Buffer to receive data
                byte[] receiveBuffer = new byte[1024];
                DatagramPacket receivePacket = new DatagramPacket(receiveBuffer, receiveBuffer.length);

                // Receive packet from client
                socket.receive(receivePacket);
                String receivedData = new String(receivePacket.getData(), 0, receivePacket.getLength());

                // Convert received data to integer
                int number = Integer.parseInt(receivedData);
                System.out.println("Received number: " + number);

                // Calculate factorial
                long factorial = calculateFactorial(number);
                String response = String.valueOf(factorial);

                // Send response to client
                byte[] sendBuffer = response.getBytes();
                InetAddress clientAddress = receivePacket.getAddress();
                int clientPort = receivePacket.getPort();

                DatagramPacket sendPacket = new DatagramPacket(sendBuffer, sendBuffer.length, clientAddress, clientPort);
                socket.send(sendPacket);
                System.out.println("Sent factorial: " + response);
            }
        } catch (Exception e) {
            System.out.println("Server error: " + e.getMessage());
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

