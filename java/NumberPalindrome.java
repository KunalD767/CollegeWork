public class NumberPalindrome{
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide a number as a command-line argument.");
            return;
        }
        String s = args[0];
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                System.out.println("The number is not a palindrome");
                return;
            }
            i++;
            j--;
        }
        System.out.println("The number is a palindrome");
    }
}
