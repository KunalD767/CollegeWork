#include<iostream>
using namespace std;
class one{
    int x,y;
    public:
    void getdata(int a,int b){
        x=a;
        y=b;
    }
    friend class two;
};
class two{
    int a,b;
    public:
    two(one x){a=x.x;b=x.y;}
    void display(){
        cout<<a<<b<<endl;
    }
    
};
int main(){
    one a;
    a.getdata(10,20);
    two b(a);
    b.display();
    return 0;
}