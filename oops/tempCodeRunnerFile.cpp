#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream fin;
    fin.open("Sample2.txt", ios::in|ios::out);
    string line;
    do{
        cout<<"ENter line";
        cin>>line;
        fin<<line;

    }while(!line.empty());
    char c;
    while(!fin.eof()){
        fin>>c;
        cout<<c;
    }
    fin.close();
    return 0;
}