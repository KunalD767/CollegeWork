#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout;
    fout.open("Sample2.txt");
    string line;
    
    do {
        cout << "Enter: ";
        getline(cin, line);
        if (!line.empty()) {
            fout << line << endl;
        }
    } while (!line.empty());

    fout.close();

    string c;
    ifstream fin;
    fin.open("Sample2.txt");

    while (getline(fin, c)) {
        cout << c << endl;
    }

    fin.close();
    return 0;
}
