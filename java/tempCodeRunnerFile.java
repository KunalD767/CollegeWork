import java.io.*;

public class filecopy {
    public static void main(String[] args) {
        String inputFile = "input.txt"; // Name of the input file
        String outputFile = "output.txt"; // Name of the output file

        try {
            // Open the input file for reading
            BufferedReader reader = new BufferedReader(new FileReader(inputFile));

            // Open the output file for writing
            BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));

            // Read from the input file and write to the output file
            String line;
            while ((line = reader.readLine()) != null) {
                writer.write(line);
                writer.newLine(); // Add a new line after each line read
            }

            // Close the reader and writer
            reader.close();
            writer.close();

            System.out.println("File copied successfully.");
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}

