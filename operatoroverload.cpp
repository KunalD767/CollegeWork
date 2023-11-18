#include<iostream>
using namespace std;
class over{
    int a,b;
    public:
    void getdata(int a,int b){
        this->a=a;
        this->b=b;
    }
    void putdata(){
        cout<<"a ="<<a;
        cout<<"b ="<<b;
    }
    
    over operator + (over x){
        over temp;    
        temp.a=a+x.a;
        temp.b=b+x.b;
        
        return temp;
    }
    void print(){
        cout<<"the value is "<<a<<"\t"<<b;
    }

};
int main(){
    cout<<"co1 is"<<endl;
    over co1,co2,co3;
    co1.getdata(2,4);
    co2.getdata(1,1);
    co3=co1+co2;
    co3.print();
    return 0;
}