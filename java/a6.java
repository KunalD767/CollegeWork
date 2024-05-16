class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}

public class a6 {
    public static void main(String[] args) {
        try {
            if (args.length != 2) {
                throw new IllegalArgumentException("Please provide name and age as arguments");
            }

            String name = args[0];
            int age = Integer.parseInt(args[1]);

            if (age < 15 || age >= 60) {
                throw new InvalidAgeException("Age must be between 15 and 59");
            }

            System.out.println("Name: " + name);
            System.out.println("Age: " + age);

        } catch (NumberFormatException e) {
            System.out.println("Error: Invalid age format. Age must be a number.");
        } catch (InvalidAgeException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
