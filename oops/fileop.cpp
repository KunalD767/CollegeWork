#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream fout;
    string line;
    fout.open("Sample.txt");
    while (fout){
        cout<<"Enter a sentence: ";
        getline(cin,line);
        if(!line.empty()){
            fout << line << endl;
            }else{
                break;
                }
                }
                fout.close();
                ifstream fin;
                fin.open("Sample.txt");
                while(getline(fin,line)){
                    cout<<line<<endl;
                }
                fin.close();
                return 0;
                }
    