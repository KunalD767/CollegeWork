#include<iostream>
using namespace std;
int g=10;
int getter(){
    return g;
}
void setter(int x){
    g=x;
}
int main(){
    int x=getter();
    setter(x);
}