#include<iostream>
using namespace std;
void add(int a[2][2],int b[2][2]);
void sub(int a[2][2],int b[2][2]);
void mul(int a[2][2],int b[2][2]);
void pri(int c[2][2]){
    int i,j;
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            cout<<"the element at index" <<i<<","<<j<< "is "<<c[i][j]<<endl;        
              }
    }
}

void div(int a[2][2],int b[2][2]);
int main(){
    int a[2][2]={{1,2},{3,4}};
    int b[2][2]={{1,2},{3,4}};
    int c;
    cout<<"1. Addition"<<endl;
    cout<<"2. subtraction"<<endl;
    cout<<"3. Scalar multiplication"<<endl;
    cout<<"4. divison "<<endl;
    cout<<"enter choice"<<endl;
    cin>>c;
    switch (c){
        case 1: 
        add(a,b);
        break;
        case 2:
        sub(a,b);
        break;
        case 3:
        mul(a,b);
        break;
        case 4:
        div(a,b);
        break;
        
    }
    return 0;
}

void add(int a[2][2],int b[2][2]){
    int i,j,c[2][2];
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    pri(c);
}
void sub(int a[2][2],int b[2][2]){
    int i,j,c[2][2];
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    pri(c);
}
void mul(int a[2][2],int b[2][2]){
    int i,j,c[2][2],k;
    cout<<"enter number you want to multiply"<<endl;
    cin>>k;
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            c[i][j]=a[i][j]*k;
        }
    pri(c);
    
    }
}
void div(int a[2][2],int b[2][2]){
    int i,j,c[2][2],k;
    cout<<"enter number you want to divide"<<endl;
    cin>>k;
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            c[i][j]=a[i][j]/k;
        }
    }
    pri(c);
}