#include<iostream>
using namespace std;
int main(){
    int a[5][2],i,j,c,d[10][3];
    int *e;
    for (i=0;i<5;i++){
        for (j=0;j<2;j++){
            cout<<"enter element at"<<i<<","<<j<<endl;
            cin>>a[i][j];
        }
    }    
    cout<<"row\tcolumn\tvalue"<<endl;   
    for (i=0;i<5;i++){
        for (j=0;j<2;j++){
            if (a[i][j]!=0){
                d[][]=a[i][j];
                cout<<i<<"\t"<<j<<"\t"<<d<<endl;
            }
        }
     }
    cout<<"enter the index you want the address of"<<endl;
    cin>>i>>j;
    e=&a[i][j];
    cout<<"the address is"<<e<<endl;
    cout<<"the address is"<<&a[i][j];
    return 0;


}