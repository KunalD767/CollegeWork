#include <iostream>
using namespace std;

template <typename T>
void swap1(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

int main() {
  int num1 = 10, num2 = 20;
  swap1(num1, num2);
  cout << "After swapping:" << endl;
  cout << "num1 = " << num1 << endl;
  cout << "num2 = " << num2 << endl;

  float float1 = 10.5f, float2 = 20.7f;
  swap1(float1, float2);
  cout << "After swapping:" << endl;
  cout << "float1 = " << float1 << endl;
  cout << "float2 = " << float2 << endl;

  char char1 = 'a', char2 = 'b';
  swap1(char1, char2);
  cout << "After swapping:" << endl;
  cout << "char1 = " << char1 << endl;
  cout << "char2 = " << char2 << endl;

  return 0;
}
