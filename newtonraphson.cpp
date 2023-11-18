#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
float f(float x){
    return(3*x-cos(x)-1);
}
float f1(float x){
    return (3+sin(x));
}
int main(){
    float x,y,y1,aerr,x1;
    int maxitr, itr=1;
    cout<<"Enter initial guess"<<endl;
    cin>>x;
    cout<<"enter approximate error"<<endl;
    cin>>aerr;
    cout<<"enter no. of iterations"<<endl;
    cin>>maxitr;
    do{
        y=f(x);
        y1=f1(x);
        if (y1==0.0){
            cout<<"invalid guess"<<endl;
            return 0;
        }
        x1=x-(y/y1);
        cout<<"the root after iterations "<<itr<<" is "<<x1<<endl;
        x=x1;
        itr++;
        if (itr>maxitr){
            cout<<"the solution is not converging after iterations "<< itr;
            return 0;

        }
    }while(fabs(f(x1))>aerr);
    cout<<"the final root is"<<setprecision(4)<<x1<<endl;
    return 0;
    
}