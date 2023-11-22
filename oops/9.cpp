#include <iostream>
using namespace std;

class Number; 

class SumCalculator {
public:
    void calculateSum(Number n);
};

class Number {
private:
    int num1;
    int num2;

public:
    Number(int n1, int n2){ num1=n1; num2=n2; }
    friend class SumCalculator;
};

void SumCalculator::calculateSum(Number n) {
    int sum = n.num1 + n.num2;
    cout << "Sum of " << n.num1 << " and " << n.num2 << " is: " << sum << endl;
}

int main() {
    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    Number numbers(num1, num2);
    SumCalculator calculator;
    calculator.calculateSum(numbers);

    return 0;
}
