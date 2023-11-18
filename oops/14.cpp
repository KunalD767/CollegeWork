#include <iostream>
using namespace std;
class basic_info {
protected:
    string name;
    int roll_no;
    char sex;
public:
    void getdata() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll_no;
        cout << "Enter sex: ";
        cin >> sex;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll number: " << roll_no << endl;
        cout << "Sex: " << sex << endl;
    }
};
class physical_fit : public basic_info {
private:
    float height;
    float weight;
public:
    void getdata() {
        basic_info::getdata();
        cout << "Enter height: ";
        cin >> height;
        cout << "Enter weight: ";
        cin >> weight;
    }
    void display() {
        basic_info::display();
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
    }
};
int main() {
    physical_fit p1;
    p1.getdata();
    p1.display();
    return 0;
}