#include <iostream>
using namespace std;

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int linear(int arr[], int x, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << "Element found at index " << i << endl;
            return i;
        }
    }
    return -1;
}

int binary(int arr[], int x, int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            cout << "Element found at index " << mid << endl;
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, n); 
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
        }
    

    cout << "Enter the number you want to search: ";
    int x;
    cin >> x;
    cout << "Enter the searching method" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    int m;
    cin >> m;

    switch (m) {
        case 1:
            linear(a, x, n);
            break;
        case 2:
            binary(a, x, n);
            break;
        default:
            cout << "Invalid choice";
    }
    return 0;
}
