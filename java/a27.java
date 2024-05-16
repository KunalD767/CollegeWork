class CustomException extends Exception {
    public CustomException(String message) {
        super(message);
    }
}

public class a27 {
    public static void main(String[] args) {
        try {
            int result = divide(10, 0);
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero");
        } catch (CustomException e) {
            System.out.println("Custom Exception: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed");
        }
    }

    public static int divide(int a, int b) throws CustomException {
        if (b == 0) {
            throw new CustomException("Cannot divide by zero");
        }
        return a / b;
    }
}
