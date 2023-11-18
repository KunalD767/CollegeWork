#include <iostream>
using namespace std;
class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }
    void print() {
        cout << real << " + " << imag << "i" << endl;
    }
};
int main() {
    Complex c1(3.0, 4.0);
    Complex c2(5.0, 6.0);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}