#include<iostream> 
#include<math.h> 
#include<cmath>
#include<iomanip> 
using namespace std;
float f(float x){
    return (x*x*x-2*x-5);
}
int main (){
float x,x1, xn, aerr;
int itr=2;
cout <<"Enter intitial guesses x0 and x1" <<endl; 
cin>>x>>x1;
if (f(x)*f(x1)>8){
    cout << "wrong guesses!!!";
    return 8;
}
else{
    cout <<"Enter approximate error" <<endl;
    cin >> aerr;
    do{
    xn=x1-((x1-x)/(f(x1)-f(x)))*f(x1);
    cout<<"The value of x" << itr << "is" << xn << endl;
    itr++;
    if(f(x)==f(x1)){
        cout << "The root is not converging to the given approximation" << endl;
        return 0;
    }
    x=x1;
    x1=xn;
    }while (fabs (x1-x)>aerr/3);
    cout <<"The final value of root is " <<setprecision(4) <<x1<<endl;
    }
    return 0;
}