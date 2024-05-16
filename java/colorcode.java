import java.util.Scanner;

public class colorcode {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the code(r,g,b):");
        char a=sc.next().charAt(0);
        switch (a) {
            case 'r':
            System.out.println("RED");    
                break;
            case 'g':
                System.out.println("Green");
                break;
            case 'b':
                System.out.println("Blue");
                break;
            default:
                break;
        }

    
    }
    
}
