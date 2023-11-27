#include<iostream>
#include<cmath>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void display(int arr[],int n){
    for (int i = 0; i < n ; ++i) {
        cout<<arr[i]<<" ";
        }
        cout<<endl;
}
void selectionsort(int arr[],int n){
    for( int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
    display(arr,n);
}
void bubblesort(int arr[], int n){
    int count=0;
    while(count<n){
    for (int i = 0; i < n - count; i++) {
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    count++;
    }
    display(arr,n);
}
void insertionsort(int arr[],int n){
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            }
            arr[j + 1] = key;
            }
            display(arr,n);
}
void quicksort(int arr[],int n){
    int pivot=arr[0];
    int i=0,j=n-1;
    while(i<j){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
            }
            }
            swap(arr[0],arr[j]);
            display(arr,n);
} 
    




int main(){
    int arr[]={5,3,1,2,4};
    int n= sizeof(arr)/sizeof(int);
    cout<<"UnSorted array is:";
    display(arr,n);
    cout<<"\n\nAfter sorting using selection sort algorithm:\t";
    selectionsort(arr,n);
    cout<<"\n\nAfter sorting using bubble sort algorithm:\t";
    bubblesort(arr,n);
    cout<<"\n\nAfter sorting using insertion sort algorithm:\t";
    insertionsort(arr,n);
    cout<<"\n\nAfter sorting using quick sort algorithm:\t";
    quicksort(arr,n);


    return 0;


}