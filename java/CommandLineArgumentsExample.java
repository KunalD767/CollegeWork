class AgeError extends Exception {
    public AgeError(String message) {
        super(message);
    }
}

public class CommandLineArgumentsExample {
    public static void main(String[] args) {
        try {
            if (args.length != 2) {
                throw new IllegalArgumentException("Usage: java CommandLineArgumentsExample <name> <age>");
            }

            String name = args[0];
            int age = Integer.parseInt(args[1]);

            validateAge(age);

            System.out.println("Name: " + name);
            System.out.println("Age: " + age);

        } catch ( IllegalArgumentException e) {
            System.err.println("Error: " + e.getMessage());
            System.err.println("Usage: java CommandLineArgumentsExample <name> <age>");

        } catch (AgeError ae) {
            System.err.println("Error: " + ae.getMessage());

        } finally {
            System.out.println("Exiting program.");
        }
    }

    private static void validateAge(int age) throws AgeError {
        if (!(15 <= age && age < 60)) {
            throw new AgeError("Age must be between 15 and 59 (inclusive)");
        }
    }
}
