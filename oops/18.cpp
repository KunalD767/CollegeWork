#include<iostream>
using namespace std;

template <typename T>
class Bigger {
private:
  T num1, num2;

public:
  Bigger(T n1, T n2) {
    num1 = n1;
    num2 = n2;
  }

  ~Bigger() {
    cout << "Destructor called" << endl;
  }

  T bigger() {
    if (num1 > num2) {
      return num1;
    } else {
      return num2;
    }
  }
};

int main() {
  Bigger<int> intObj(10, 20);
  int biggerInt = intObj.bigger();
  cout << "The bigger integer is: " << biggerInt << endl;

  Bigger<float> floatObj(10.5f, 20.7f);
  float biggerFloat = floatObj.bigger();
  cout << "The bigger float is: " << biggerFloat << endl;

  return 0;
}
