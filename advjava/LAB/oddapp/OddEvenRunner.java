package oddapp;
public class OddEvenRunner {
    
    class SharedNumber {
        private int num = 1;
        private int ocount, ecount, oddprint = 0, evenprint = 0;
        private StringBuilder output = new StringBuilder();

        public SharedNumber(int ocount, int ecount) {
            this.ocount = ocount;
            this.ecount = ecount;
        }

        public synchronized void printOdd() {
            while (oddprint < ocount) {
                while (num % 2 == 0) {
                    try {
                        wait();
                    } catch (InterruptedException ignored) {}
                }
                output.append(num).append(" ");
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
                    } catch (InterruptedException ignored) {}
                }
                output.append(num).append(" ");
                num++;
                evenprint++;
                notifyAll();
            }
        }

        public String getOutput() {
            return output.toString();
        }
    }

    // Inner class: Odd number printer thread
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

    private int ocount;
    private int ecount;

    public OddEvenRunner(int ocount, int ecount) {
        this.ocount = ocount;
        this.ecount = ecount;
    }

    // Method to run threads and capture output
    public String runThreads() throws InterruptedException {
        SharedNumber shared = new SharedNumber(ocount, ecount);
        Thread oddThread = new OddThread(shared);
        Thread evenThread = new EvenThread(shared);

        oddThread.start();
        evenThread.start();

        oddThread.join();
        evenThread.join();

        return shared.getOutput();
    }
}