#include <iostream>
using namespace std;
class STUDENT {
protected:
    int roll_no;
    string name;
public:
    void get_student_info() {
        cout << "Enter roll number: ";
        cin >> roll_no;
        cout << "Enter name: ";
        cin >> name;
    }
};
class EXAM : public STUDENT {
protected:
    int marks[6];
public:
    void get_marks() {
        cout << "Enter marks in six subjects: ";
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }
};
class RESULT : public EXAM {
private:
    int total_marks;
public:
    void calculate_total_marks() {
        total_marks = 0;
        for (int i = 0; i < 6; i++) {
            total_marks += marks[i];
        }
    }
    void display_result() {
        cout << "Roll number: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "Total marks: " << total_marks << endl;
    }
};
int main() {
    RESULT r1;
    r1.get_student_info();
    r1.get_marks();
    r1.calculate_total_marks();
    r1.display_result();
    return 0;
}