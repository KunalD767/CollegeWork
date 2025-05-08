#include<iostream>
#include<cmath>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int,int> a;
    a[0]=1;
    a[0]++;
    a[1] = 0;
    for (auto it : a) {
        cout << it.first << " " << it.second << endl;
    }
}