import java.rmi.Naming;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            Calculator calc = (Calculator) Naming.lookup("rmi://localhost/CalculatorService");
            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.println("\n===== Calculator Menu =====");
                System.out.println("1. Add");
                System.out.println("2. Subtract");
                System.out.println("3. Multiply");
                System.out.println("4. Divide");
                System.out.println("5. Exit");
                System.out.print("Choose an option: ");

                int choice = scanner.nextInt();
                if (choice == 5) {
                    System.out.println("Exiting...");
                    break;
                }

                System.out.print("Enter first number: ");
                double a = scanner.nextDouble();
                System.out.print("Enter second number: ");
                double b = scanner.nextDouble();

                switch (choice) {
                    case 1:
                        System.out.println("Result: " + calc.add(a, b));
                        break;
                    case 2:
                        System.out.println("Result: " + calc.subtract(a, b));
                        break;
                    case 3:
                        System.out.println("Result: " + calc.multiply(a, b));
                        break;
                    case 4:
                        if (b == 0) {
                            System.out.println("Error: Division by zero.");
                        } else {
                            System.out.println("Result: " + calc.divide(a, b));
                        }
                        break;
                    default:
                        System.out.println("Invalid option. Please try again.");
                        break;
                }
            }

            scanner.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
