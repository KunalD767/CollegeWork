class A extends Thread{
    public void run(){
        String s=Thread.currentThread().getName();
        try{
            for(int i=0;i<4;i++){
            
            System.out.println(s);
            sleep(1000);
            
        }
    }
    catch(InterruptedException e){
        System.out.println("ch");
    }

        
      
    }
}
class B extends Thread{
    public void run(){
        String s=Thread.currentThread().getName();
        for(int i=0;i<4;i++){
            
            System.out.println(s);
            
        }
    }
}
class join{
    public static void main(String[] args) {
        A t1= new A();
        B t2= new B();
        t2.setName("HEllo");
        t1.setName("bka");
        t1.start();
        t1.interrupt();
        t2.start();        
    }
       
        
}