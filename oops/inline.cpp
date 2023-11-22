#include <iostream>

using namespace std;

class MyClass {
  private:
    int x;

  public:
    MyClass(int x) : x(x) {}

    friend void printX(MyClass& obj) {
      cout << obj.x;
    }
};

int main() {
  MyClass obj(10);

  printX(obj);

  return 0;
}