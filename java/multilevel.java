import java.util.Scanner;

public class multilevel {
    Scanner sc = new Scanner(System.in);
    public class Student {
        String a;
        int rollno;
        public void Getinfo() {
            System.out.println("Enter the name of student");
            a = sc.nextLine();
            System.out.println("Enter the roll number of student");
            rollno = sc.nextInt();
        }
        public void displayinfo() {
            System.out.println(a + "\t" + rollno);
        }
    }

    public class Test extends Student {
        int[] marks = new int[5];

        public void Getmarks() {
            System.out.println("Enter marks for 5 subjects:");
            for (int i = 0; i < 5; i++) {
                marks[i] = sc.nextInt();
            }
        }
    }
    public class Result extends Test{
        int sum=0;
        public void Avg() {
            for (int i = 0; i < 5; i++) {
                sum += marks[i];
            }
            System.out.println("Total marks are " + sum + " And percentage  is " + (sum*100/500)+"%");
        }
    }
    public static void main(String[] args) {
        multilevel instance = new multilevel();
        multilevel.Result a = instance.new Result();
        a.Getinfo();
        a.displayinfo();
        a.Getmarks();
        a.Avg();

    }
    
}
