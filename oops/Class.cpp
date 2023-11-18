#include<iostream>
using namespace std;
class stu{
    public:
    string name;
    string subject[5];
    int marks[5];
    void get_data();
    void calc();
    void print();
};
void stu::get_data()
    {
    int i;
    int c;
    int N;
    cout << " Enter the number of students";
    cin >> N;

    int j;
    stu d[2];

    for (i=0;i<N;i++){
        string a;
        
        
        cout<<"enter name"<<endl;
        cin>>a;
        d[i].name=a;
        for (j=0;j<5;j++){
            string b;
            cout<<"enter subject"<<endl;
            cin>>b;
            d[i].subject[j]=b;
            cout<<"enter marks"<<endl;
            cin>>c;
            d[i].marks[j]=c;
        }

         
    }
}
void stu :: calc() {
    int i;
    int c;
    int j;
    stu d[2];
    int sum; int n;
        sum=0;
        for (j=0;j<5;j++){
            sum=sum+d[i].marks[j];
            
        }
        n=(sum/500)*100;
        
        
    }
void stu :: print(){
    int i;
    int c;
    int j;
    int N;
    stu d[2];
    int n;
    for (i=0;i<N;i++){
        if(n>70){
            cout<<"the name of the student is "<<d[i].name;
        }
    }
}
    
    int main() {
        int N;
        stu sc[N];
        cout<< " Enter the number of students";
        cin >> N;
        for(int i=0; i< N; i++){
            sc[i].get_data();
            sc[i].calc();
        }
        for(int i=0;i<N;i ++){
            sc[i].print();
        }
    }