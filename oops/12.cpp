#include <iostream>
using namespace std;
class Counter {
private:
    static int numObjects;  
public:
    Counter() { numObjects++; } 
    ~Counter() { numObjects--; }  
    static int getNumObjects() { return numObjects; }  
};
int Counter::numObjects = 0; 
int main() {
    Counter c1;  
    Counter c2;  
    cout << "Number of objects: " << Counter::getNumObjects() << endl;  // print the number of objects
    return 0;
}