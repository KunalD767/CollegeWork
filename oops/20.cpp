#include <iostream>
using namespace std;

template <typename T>
T max1(T a, T b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

template <typename T>
T max1(T a, T b, T c) {
  return max1(max1(a, b), c);
}

int main() {
  int num1 = 10, num2 = 20;
  int maxInt = max1(num1, num2);
  cout << "The maximum of " << num1 << " and " << num2 << " is: " << maxInt << endl;

  float float1 = 10.5, float2 = 20.7;
  float maxFloat = max1(float1, float2);
  cout << "The maximum of " << float1 << " and " << float2 << " is: " << maxFloat << endl;

  int num3 = 30;
  int maxInt3 = max1(num1, num2, num3);
  cout << "The maximum of " << num1 << ", " << num2 << " and " << num3 << " is: " << maxInt3 << endl;

  float float3 = 30.7;
  float maxFloat3 = max1(float1, float2, float3);
  cout << "The maximum of " << float1 << ", " << float2 << " and " << float3 << " is: " << maxFloat3 << endl;

  return 0;
}
