#include<iostream>
using namespace std;
class areashape{
    public:
        int area(int a, int b);
        int area(float a, float b);
        int area(float a);
        int area(int a);
    
};
int areashape::area(int a, int b){
    cout<<"enter the base and height"<<endl;
    cin>>a>>b;
    float area=a*b*0.5;
    cout<<"the area is"<<area;

    return 0;
}
int areashape::area(float a, float b){
    cout<<"enter the base and height"<<endl;
    cin>>a>>b;
    float area=a*b*0.5;
    cout<<"the area is"<<area;

    return 0;
}
int areashape::area(float a){
    cout<<"enter the side length"<<endl;
    cin>>a;
    float area=a*a;
    cout<<"the area is"<<area;
    return 0;
}
int areashape::area(int a){
    cout<<"enter the side length"<<endl;
    cin>>a;
    float area=a*a;
    cout<<"the area is"<<area;
    return 0;
}
int main(){
    float a,b;
    int d,e,c,f;
    areashape s;  
    cout<<"enter the shape you want the are of"<<endl;
    cout<<"1.triangle(int)"<<endl;
    cout<<"2.triangle(float)"<<endl;
    
    cout<<"3.square(int)"<<endl;
    cout<<"4.square(float)"<<endl;

    cin>>c;
    switch (c)
    {
    case 1:
        s.area(d,e);
        break;
    case 2:
        s.area(a,b);
        break;
    case 3:
        s.area(d);
        break;
    case 4:
        s.area(a);
        break;
    default:
        break;
    }
    
    return 0;
       
} 