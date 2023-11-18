#include<iostream>
using namespace std;
class difference{
    
    int  n, *a;
    public:
    difference(){n=10;a=new int[10];}
    difference(int a){n=a;this->a=new int[n];}
    void input(){
        cout<<"Enter elements";
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            }
        }
        void output(){
            cout<<"The array is : ";
            for(int j=0;j<n;++j){
                cout<<a[j]<<" ";
                }
                cout<<endl;
                }
                 friend int diff(difference a,int N);
            };
            int diff(difference a,int N){
                for (int i=0;i<a.n;i++){
                    for(int j=i+1;j<a.n;j++){
                        if(a.a[j]-a.a[i]==N){
                            cout<<"Yes, There exists a pair "<<a.a[i]<<" and "<<a.a[j]<<" whose difference is "<<N;
                            return 1;
                        }
                    }
                }
                cout<<"There does not exist a pair whose difference is N";
                return 0;
            }
            int main(){
                difference a(6);
                a.input();
                a.output();
                int N;
                cout<<"Enter the number to find pairs of elements with difference equal to it.";
                cin>>N;
                diff(a,N);
                return 0;
            }    