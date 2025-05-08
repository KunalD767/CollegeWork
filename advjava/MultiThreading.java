class ThreadExample extends Thread {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(getName() + " - Count: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println("Thread " + getName() + " interrupted.");
            }
        }
        System.out.println(getName() + " has finished execution.");
    }
}

class RunnableExample implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(Thread.currentThread().getName() + " - Square: " + (i * i));
            try {
                Thread.sleep(700);
            } catch (InterruptedException e) {
                System.out.println("Thread " + Thread.currentThread().getName() + " interrupted.");
            }
        }
        System.out.println(Thread.currentThread().getName() + " has finished execution.");
    }
}

public class MultiThreading {
    public static void main(String[] args) {
        System.out.println("Kajal Kansal 20914802722");

        ThreadExample thread1 = new ThreadExample();
        thread1.setName("Thread-1");

        RunnableExample runnableTask = new RunnableExample();
        Thread thread2 = new Thread(runnableTask, "Thread-2");

        thread1.start();
        thread2.start();

        for (int i = 1; i <= 5; i++) {
            System.out.println("Main Thread - Cube: " + (i * i * i));
            try {
                Thread.sleep(400);
            } catch (InterruptedException e) {
                System.out.println("Main Thread interrupted.");
            }
        }
        System.out.println("Main Thread has finished execution.");
    }
}
