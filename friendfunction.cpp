#include<iostream>
using namespace std;
class obj2;
class ob1{
    private:
    int x,y;
    static int b;
    public:
    void print(){
        cout<<x<<y<<b;
    }
    void set(int a,int c){
        x=a;
        y=c;
        b=b+1;

    }

};
int ob1::b;
int main(){
    ob1 a,c;
    a.set(2,4);
    a.print();
    c.set(3,2);
    c.print();
    return 0;
}