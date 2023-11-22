#include <iostream>
using namespace std;
class twostack {
private:
    int* array;
    int size;
    int top1; 
    int top2; 

public:
    twostack(int size) {
        this->size = size;
        array = new int[size];
        top1 = -1;
        top2 = size;
    }
   
    void push1(int value) {
        if (top1 < top2 - 1) {
            array[++top1] = value;
        } else {
            cout << "Stack 1 is full, cannot push " << value << endl;
        }
    }

    
    void push2(int value) {
        if (top2 > top1 + 1) {
            array[--top2] = value;
        } else {
            cout << "Stack 2 is full, cannot push " << value << endl;
        }
    }

   
    int pop1() {
        if (top1 >= 0) {
            return array[top1--];
        } else {
            cout << "Stack 1 is empty." << endl;
            return -1; 
        }
    }

    int pop2() {
        if (top2 < size) {
            return array[top2++];
        } else {
            cout << "Stack 2 is empty." << endl;
            return -1; 
        }
    }
    void printStack1() {
        cout << "Stack 1: ";
        for (int i = 0; i <= top1; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Print the contents of stack 2
    void printStack2() {
        cout << "Stack 2: ";
        for (int i = size - 1; i >= top2; --i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    twostack twostack(10);

    twostack.push1(1);
    twostack.push1(2);
    twostack.push1(3);

    twostack.push2(10);
    twostack.push2(9);
    twostack.push2(8);
    twostack.printStack1();
    twostack.printStack2();

    cout << "Pop from stack 1: " << twostack.pop1() << endl;
    cout << "Pop from stack 2: " << twostack.pop2() << endl;

    return 0;
}
