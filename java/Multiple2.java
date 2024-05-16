import java.util.Scanner;

public class Multiple2 {
    Scanner sc = new Scanner(System.in);

    interface Student {
        void Getinfo();

        void displayinfo();
    }

    interface Sports {
        void Getsports();
    }

    public class Result implements Sports, Student {
        String a;
        int rollno;
        String[] marks = new String[2];

        
        public void Getinfo() {
            System.out.println("Enter the name of student");
            a = sc.nextLine();
            System.out.println("Enter the roll number of student");
            rollno = sc.nextInt();
        }

        
        public void displayinfo() {
            System.out.println(a + "\t" + rollno);
        }

        
        public void Getsports() {
            System.out.println("Enter Sports of student");
            for (int i = 0; i < 2; i++) {
                marks[i] = sc.nextLine();
            }
        }

        public void Avg() {
            for (int i = 0; i < 2; i++) {
                System.out.println(marks[i]);
            }
        }
    }

    public static void main(String[] args) {
        Multiple2 instance = new Multiple2();
        Multiple2.Result a = instance.new Result();
        a.Getinfo();
        a.displayinfo();
        a.Getsports();
        a.Avg();
    }
}
