#include <iostream>
using namespace std;
void Sort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int maximumToys(int arr[], int n, int k) {
    Sort(arr,n);
    int count = 0;
    int amt = k;

    for (int i = 0; i < n; ++i) {
        if (arr[i] <= amt) {
            amt -= arr[i]; 
            count++; 
        } else {
            break; 
        }
    }

    return count;
}

int main() {
    int arr[] = {1, 12, 5, 111, 200}; 
    int k = 50;

    int n = sizeof(arr) / sizeof(arr[0]); 
    int maxToys = maximumToys(arr, n, k);

    cout << "Maximum number of toys that can be bought: " << maxToys << endl;

    return 0;
}
