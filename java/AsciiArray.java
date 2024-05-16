public class AsciiArray {
    public static void main(String[] args) {
        int[] asciiArray = {65, 66, 67, 97, 98, 99};
        System.out.print("Corresponding characters: ");
        for (int value : asciiArray) {
            char character = (char) value;
            System.out.print(character + " ");
        }
    }
}
