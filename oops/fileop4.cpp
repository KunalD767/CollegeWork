#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream in("in.txt"); 
    ofstream out("out.txt"); 

    if (!in || !out) {
        cout << "File opening failed.";
        return 1;
    }
    string s="Hello World, How are you?",s1="cat";
    char ch;
    while (in.get(ch)) {
        if (ch != ' ' && ch != '\t' && ch != '\v' && ch != '\n' && ch != '\r') {
            out << ch;
        }
    }

    in.close();
    out.close();

    cout << "White spaces removed and stored in 'output.txt'.";

    return 0;
}
