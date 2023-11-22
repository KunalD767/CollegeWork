#include<iostream>
using namespace std;

class one;
class two;

class one
{
    int a = 10;
    public:
    friend int cal(one a,two b);

};
class two
{
    int b = 20;
    public:
    friend int cal(one a,two b);

};

int cal(one x,two y)
{
    int ans;
    if(x.a>y.b){
        ans=x.a;
    }
    else{
        ans=y.b;
    }
    cout<<"the greater no. is "<<ans<<endl;
}

int main()
{
    one x;
    two y;
    cal(x,y);
}