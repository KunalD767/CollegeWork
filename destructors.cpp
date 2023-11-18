#include<iostream>
using namespace std;
int a=0;
class ob1{
    public:

    ob1(){++a;cout<<"a++="<<a;}
    ~ob1(){--a;cout<<"a--="<<a;}
};
int main(){
    ob1 a,b,c,d;
    {
        ob1 e,f,g,h;
    }
    
}