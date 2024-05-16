class A{
    int x=10;
    void m1(){
        System.out.println(x);
    }
};
class b extends A{
    int y=20;
    void m1(){
        System.out.println(y);
    }
};

public class inherit {
    public static void main (String[] args){
        b a= new b();
        a.m1();
    }

    
}