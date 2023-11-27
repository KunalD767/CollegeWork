#include<iostream>
using namespace std;
class arr{
    
    int n;
    public:
    int *a;
    arr(){
        a= new int[10]; 
    }
    arr(int n){this->n=n; a = new int[n];}
    void displayindex(int c){
        try{
        if (n<=c){
            throw(c);
        }
        else{
            cout<<a[c]<<endl;
        }
        }
        catch(int e) {
            cout << "Index out of bound" << endl;
        }
    }
};
int main(){

    arr obj(3);
    for(int i=0;i<=2;i++){
        cout<<"Enter element at index: "<<i<<endl;
        cin>>obj.a[i];
        }
    obj.displayindex(2);
    obj.displayindex(3);
    return 0;


}