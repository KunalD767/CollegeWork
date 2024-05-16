public class stackqueue {
    private int size=100;
    private int[] stack=new int[100];
    private int[] queue=new int[100];
    private int top=-1;
    private int front=-1,rear=-1;

    public void push(int value) {
        if(top<size-1){
            top++;
            stack[top]=valaue;
        }
        else{
            System.out.println( "Stack overflow");
        }
    }

    public int pop() {
        if (top >= 0) {
            int x=stack[top];
            top--;
            return x;
        } else {
            System.out.println("Stack underflow.");
            return -1;
        }
    }

    public void enqueue(int value) {
        if(front!=-1 && rear<size-1){
            rear++;
            queue[rear]=value;
        }
        if (front==-1&&rear==-1) {
           front=rear=0;
           queue[rear] = value;

        }
       
        if(rear==size-1){
            System.out.println("Queue is full");

        }
    }

    public int dequeue() {
        if (front <= rear && front != -1) {
            return queue[front++];
        } else {
            System.out.println("Queue underflow.");
            return -1;
        }
    }

    public void Stackdisplay() {
        System.out.print("Stack: ");
        for (int i = 0; i <= top; i++) {
            System.out.print(stack[i] + " ");
        }
        System.out.println();
    }
    public void Queuedisplay() {
        System.out.print("Queue: ");
        for (int i = front; i <= rear; i++) {
            System.out.print(queue[i] + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {
        stackqueue stackQueue = new stackqueue();
        stackQueue.push(1);
        stackQueue.push(2);
        stackQueue.push(3);
        stackQueue.Stackdisplay();

        System.out.println("Pop from stack: " + stackQueue.pop());
        stackQueue.Stackdisplay();
        stackQueue.enqueue(4);
        stackQueue.enqueue(5);
        stackQueue.enqueue(6);
        stackQueue.Queuedisplay();

        System.out.println("Dequeue from queue: " + stackQueue.dequeue());
        stackQueue.Queuedisplay();
    }
}
