import java.util.Scanner;

class SharedNumber {
    private int num = 1;
    private int ocount;
    private int ecount;
    private int oddprint = 0;
    private int evenprint = 0;

    public SharedNumber(int ocount, int ecount) {
        this.ocount = ocount;
        this.ecount = ecount;
    }

    public synchronized void printOdd() {
        while (oddprint < ocount) {
            while (num % 2 == 0) {
                try {
                    wait();
                } catch (InterruptedException e) {}
            }
            System.out.print(num + " ");
            num++;
            oddprint++;
            notifyAll();
        }
    }

    public synchronized void printEven() {
        while (evenprint < ecount) {
            while (num % 2 != 0) {
                try {
                    wait();
                } catch (InterruptedException e) {}
            }
            System.out.print(num + " ");
            num++;
            evenprint++;
            notifyAll();
        }
    }
}

class OddThread extends Thread {
    private SharedNumber shared;

    public OddThread(SharedNumber shared) {
        this.shared = shared;
    }

    public void run() {
        shared.printOdd();
    }
}

class EvenThread extends Thread {
    private SharedNumber shared;

    public EvenThread(SharedNumber shared) {
        this.shared = shared;
    }

    public void run() {
        shared.printEven();
    }
}

public class OddEven {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of odd numbers: ");
        int ocount = scanner.nextInt();

        System.out.print("Enter number of even numbers: ");
        int ecount = scanner.nextInt();
        scanner.close();

        SharedNumber shared = new SharedNumber(ocount, ecount);

        Thread oddThread = new OddThread(shared);
        Thread evenThread = new EvenThread(shared);

        System.out.println("Numbers in Sequence:");
        oddThread.start();
        evenThread.start();
    }
}