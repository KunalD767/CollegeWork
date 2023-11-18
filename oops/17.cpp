#include<iostream>
using namespace std;
template <typename T>
T square(T num) {
  return num * num;
}
int main() {
  int num1 = 5;
  cout << "The square of " << num1 << " is " << square(num1) << endl;
  float num2 = 3.14;
  cout << "The square of " << num2 << " is " << square(num2) << endl;
  double num3 = 12.345;
  cout << "The square of " << num3 << " is " << square(num3) << endl;
  return 0;
}