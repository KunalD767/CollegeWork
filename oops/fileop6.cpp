#include<iostream>
#include<fstream>
using namespace std;
class student{
    public:
    string name,id;
    int age;
    char sex;
    float height,weight;

};
int main(){
    student *s;
    s=new student[100];
    ofstream f;
    f.open("x.txt");
    if(!f){
        cout<<"File not found";
        return 0;
        }
        char b='y';
        int i=0;
        while(b=='y'|| b=='Y'){
                cout<<"\n\tStudent "<<i+1<<": \n";
                cout<<"Name: ";
                cin>>s[i].name;
                cout<<"ID: ";
                cin>>s[i].id;
                cout<<"Age: ";
                cin>>s[i].age;
                cout<<"Sex (M/F): ";
                cin>>s[i].sex;
                cout<<"Height in cm: ";
                cin>>s[i].height;
                cout<<"Weight in kg: ";
                cin>>s[i].weight;
                f<<"The Name of the student is "<<s[i].name<<" , The ID is "<< s[i].id << " ,The age is "<<
                s[i].age<<" ,The sex is"<< s[i].sex<< " ,the height and weight are"<<s[i].height<<" "<<s[i].weight<<endl;
            
            cout<<"Do you want to add more students? (Y/N) : ";
            cin>>b;
            i++;

            }
            f.close();
        ifstream a;
        a.open("x.txt");
        string in;
        while(!a.eof()){
            getline(a,in);
            cout<<in<<endl;
           

        }
        a.close();
        delete[] s;
        return 0;
}