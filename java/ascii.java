import java.util.Scanner;
public class ascii {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a character: ");
        char inputChar = sc.next().charAt(0);
        int ASCIIValue = (int)inputChar;
        System.out.println("The ASCII value of "+inputChar+" is "+ASCIIValue);
        }
    }
    
