#include <iostream>
using namespace std;
int main(){
    int* a = new int; 

    if (a == nullptr) {
        cout << "Memory allocation failed." <<endl;
        return 1; 
    }
    *a = 42;

    cout << "Dynamically allocated integer: " << *a <<endl;

    
    delete a;
    cout<<"after deletion *a="<<*a;

    return 0; 
}