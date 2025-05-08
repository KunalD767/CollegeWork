import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class UDPClient {
   public UDPClient() {
   }

   public static void main(String[] var0) {
      String var1 = "localhost";
      short var2 = 5060;

      try {
         DatagramSocket var3 = new DatagramSocket();

         try {
            Scanner var4 = new Scanner(System.in);

            try {
               System.out.print("Enter a number to find its factorial: ");
               int var5 = var4.nextInt();
               byte[] var6 = String.valueOf(var5).getBytes();
               InetAddress var7 = InetAddress.getByName(var1);
               DatagramPacket var8 = new DatagramPacket(var6, var6.length, var7, var2);
               var3.send(var8);
               byte[] var9 = new byte[1024];
               DatagramPacket var10 = new DatagramPacket(var9, var9.length);
               var3.receive(var10);
               String var11 = new String(var10.getData(), 0, var10.getLength());
               System.out.println("Factorial of " + var5 + " is: " + var11);
            } catch (Throwable var14) {
               try {
                  var4.close();
               } catch (Throwable var13) {
                  var14.addSuppressed(var13);
               }

               throw var14;
            }

            var4.close();
         } catch (Throwable var15) {
            try {
               var3.close();
            } catch (Throwable var12) {
               var15.addSuppressed(var12);
            }

            throw var15;
         }

         var3.close();
      } catch (Exception var16) {
         System.out.println("Client error: " + var16.getMessage());
      }

   }
}
