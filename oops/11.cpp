#include <iostream>
using namespace std;
class Fibonacci {
private:
    int num1;
    int num2;
public:
    Fibonacci(int n1 = 0, int n2 = 1) : num1(n1), num2(n2) {}
    Fibonacci(const Fibonacci &obj) {
        num1 = obj.num1;
        num2 = obj.num2;
    }
    void printFibonacci(int n) {
        cout << num1 << " " << num2 << " ";
        for (int i = 2; i < n; i++) {
            int nextNum = num1 + num2;
            cout << nextNum << " ";
            num1 = num2;
            num2 = nextNum;
        }
    }
};
int main() {
    Fibonacci f1;
    f1.printFibonacci(10);
    cout << endl;
    Fibonacci f2(f1);
    f2.printFibonacci(10);
    return 0;
}