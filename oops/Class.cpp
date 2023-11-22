#include <iostream>
using namespace std;

class stu {
public:
    string name;
    string subject[5];
    int marks[5];
    void get_data();
    float calc(); 
    void print(float percentage); 
};

void stu::get_data() {
    cout << "Enter name: ";
    cin >> name;
    for (int j = 0; j < 5; j++) {
        cout << "Enter subject " << j + 1 << " name: ";
        cin >> subject[j];
        cout << "Enter marks for subject " << subject[j] << ": ";
        cin >> marks[j];
    }
}

float stu::calc() {
    int sum = 0;
    for (int j = 0; j < 5; j++) {
        sum += marks[j];
    }
    return (sum / 500.0) * 100; 
}

void stu::print(float percentage) {
    if (percentage > 70) {
        cout << "Name: " << name << ", Percentage: " << percentage << "%" << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;
    stu sc[N];

    for (int i = 0; i < N; i++) {
        sc[i].get_data();
    }

    for (int i = 0; i < N; i++) {
        float percentage = sc[i].calc();
        sc[i].print(percentage);
    }
    return 0;
}
