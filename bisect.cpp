
#include <iostream>
#include<iomanip>
#include<math.h>
#include<conio.h>
using namespace std;
float f (float x){
return (x*x*x - 4*x - 9);
}
void bisect (float *x, float a, float b,int *itr){
*x = (a + b) /2;
++ (*itr) ;
cout <<" Iteration no. "<<setw(3)<<*itr<<" X= "<< setw(7)<< setprecision(5)<<*x<<endl;
}
int main (){
int itr =0, maxitr;
float x, a,b, aerr , xl, fixed;
cout << "Enter the values of a,b,"<< "allowed error,maximum iterations"<< endl;
cin >> a >> b >> aerr >> maxitr;
cout << fixed<<endl;
bisect (&x, a,b, &itr);
do
{
if (f(a)*f(x) < 0)
b=x;
else
a = x;
bisect (&xl, a,b, &itr) ;
if (fabs (xl-x) < aerr)
{
cout << "After " << itr << " iterations, root"<<"="<< setw(6) << setprecision(4)<< xl << endl;
return 0;
}
x = xl;
}
while (itr<maxitr);
cout << "Solution does not converge," << "iterations not sufficient" << endl; 
return 0;

}                                                 