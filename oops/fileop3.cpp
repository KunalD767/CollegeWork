#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream f;
    f.open("Sample.txt");
    if(!f){
        cout<<"File not found";
        return 0;
        }
        string s="Hello Kunal";
        f<<s;
        f.close();
        ifstream a;
        a.open("Sample.txt");
        string in;
        while(!a.eof()){
            getline(a,in);
            cout<<in<<endl;

        }
        a.close();
        return 0;
}