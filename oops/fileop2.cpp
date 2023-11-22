#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream fin;
    fin.open("Sample2.txt");
    string line;
    do {
        cout<<"Enter";
        cin>>line;
        fin<<line;
    }while(!line.empty());
    string c;
    ifstream fout;
    
    while(!fout.eof()){
        fout>>c;
        cout<<c;

    }
    fin.close();
    fout.close();
    return 0;
}