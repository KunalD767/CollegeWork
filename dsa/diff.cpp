#include<iostream>
using namespace std;
class differerence{
    
    int  n, *a;
    public:
    differerence(){n=10;a=new int[10];}
    differerence(int a){n=a;this->a=new int[n];}
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
                 friend int differ(differerence a,int N);
            };
            int differ(differerence a,int N){
                for (int i=0;i<a.n;i++){
                    for(int j=i+1;j<a.n;j++){
                        if(a.a[j]-a.a[i]==N){
                            cout<<"Yes, There exists a pair "<<a.a[i]<<" and "<<a.a[j]<<" whose differerence is "<<N;
                            return 1;
                        }
                    }
                }
                cout<<"There does not exist a pair whose differerence is N";
                return 0;
            }
            int main(){
                differerence a(6);
                a.input();
                a.output();
                int N;
                cout<<"Enter the number to find pairs of elements with differerence equal to it.";
                cin>>N;
                differ(a,N);
                return 0;
            }    