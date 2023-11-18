#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int a,b,c,d,e,f,g,h;
    cout <<"enter coefficients of a,b,c"<< endl;
    cin >>a>>b>>c;
    d=(b*b)-(4*a*c);
    if (d>0){
        e=(-b+sqrt(d))/(2*a);
        f=(-b-sqrt(d))/(2*a);
        cout<<"root 1 is"<<e<<endl;
        cout<<"root 2 is"<<f<<endl;
    }
    return 0;
}