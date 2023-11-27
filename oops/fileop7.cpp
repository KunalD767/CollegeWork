#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream f;
    f.open("Base.txt",ios::out | ios::in);
    if(!f){
        cout<<"File not found";
        return 0;
        }
        string s="Hello World! How are you";
        string s1="Color";

        f<<s<<endl;
        f<<s1;
        f.seekg(0,ios::beg);
        string in;
        fstream a;
        a.open("Copied.txt",ios::out);
        if (!a){
            cout<<"File not created";
            return 0;
            
        }
        while(!f.eof()){
            getline(f,in);
            cout<<in<<endl;
            a<<in<<endl;

        }
        f.close();
        return 0;
}