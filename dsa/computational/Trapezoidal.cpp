#include <iostream>
using namespace std;

float y(float x) {
    return 1 / (1 + x * x);
}

float trapezoidal(float x0, float xn, int n) {
    float step = (xn - x0) / n;
    float sum = y(x0) + y(xn);
    
    for (int i = 1; i < n; i++) {
        sum += 2 * y(x0 + step * i);
    }
    
    return (step / 2) * sum;
}

int main() {
    cout << "PARSHANT KUMAR GUPTA" << endl;
    cout << "75214802722" << endl;
    
    float x0 = 0, xn = 1;
    int n = 12;
    
    cout << "Value of the integral is " << trapezoidal(x0, xn, n) << endl;
    return 0;
}
