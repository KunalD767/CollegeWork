public class floydsformat {
    public static void main(String[] args) {
        char a = '*';
        int rows = 10;

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(a + " ");
            }
            System.out.println();
        }
    }
}
