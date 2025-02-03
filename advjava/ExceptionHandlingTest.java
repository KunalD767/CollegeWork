import java.util.Scanner;

class NegativeValueException extends Exception {
    public NegativeValueException(String message) {
        super(message);
    }
}

class OutOfRangeException extends Exception {
    public OutOfRangeException(String message) {
        super(message);
    }
}

public class ExceptionHandlingTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter name of Student 1: ");
            String student1 = scanner.nextLine();
            System.out.print("Enter marks for 3 subjects (Student 1): ");
            int m1 = getValidMarks(scanner);
            int m2 = getValidMarks(scanner);
            int m3 = getValidMarks(scanner);

            System.out.print("Enter name of Student 2: ");
            String student2 = scanner.nextLine();
            System.out.print("Enter marks for 3 subjects (Student 2): ");
            int m4 = getValidMarks(scanner);
            int m5 = getValidMarks(scanner);
            int m6 = getValidMarks(scanner);

            double average1 = (m1 + m2 + m3) / 3.0;
            double average2 = (m4 + m5 + m6) / 3.0;

            System.out.println(student1 + "'s Average Marks: " + average1);
            System.out.println(student2 + "'s Average Marks: " + average2);

        } catch (NumberFormatException e) {
            System.out.println("Error: Invalid input. Please enter an integer.");
        } catch (NegativeValueException | OutOfRangeException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static int getValidMarks(Scanner scanner) throws NegativeValueException, OutOfRangeException {
        int marks = Integer.parseInt(scanner.nextLine());

        if (marks < 0) {
            throw new NegativeValueException("Marks cannot be negative.");
        }
        if (marks > 100) {
            throw new OutOfRangeException("Marks should be in the range of 0-100.");
        }
        return marks;
    }
}
