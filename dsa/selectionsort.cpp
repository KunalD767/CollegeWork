#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    display(arr, n);
}

void bubblesort(int arr[], int n) {
    for (int count = 0; count < n - 1; count++) {
        for (int i = 0; i < n - count - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    display(arr, n);
}

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    display(arr, n);
}

void quick(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low, j = high;
        while (i < j) {
            while (arr[i] <= pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        quick(arr, low, j - 1);
        quick(arr, j + 1, high);
    }
    
}
void quicksort(int arr[], int low, int high) {
    quick(arr,low,high);
    display(arr, high+1-low);
    }


void merge(int *array, int l, int m, int r) {
    int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {     
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     
      array[k] = rarr[j];
      j++; k++;
   }
}

void mergeSort(int *array, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
        
    }
}
void merge(int *array, int l, int r){
    mergeSort(array,l,r);
    display(array,r-l+1);

}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest);
    }

}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    display(arr, n);
}

int main() {
    int arr[] = {5, 3, 1, 2, 4};
    int a;
    int n = sizeof(arr) / sizeof(int);
    cout<<"Enter the sorting method you want to use"<<endl;
    cout<<"1: Selection Sort"<<endl;
    cout<<"2: Bubble Sort"<<endl;
    cout<<"3: Insertion Sort"<<endl;
    cout<<"4: Quick Sort"<<endl;
    cout<<"5: Merge Sort"<<endl;
    cout<<"6: Heap Sort"<<endl;
    cin>>a;
    cout << "UnSorted array is:";
    display(arr, n);
    switch(a){
        case 1:
            cout << "After sorting using selection sort algorithm:" << endl;
            selectionsort(arr, n);
            break;
        case 2: 
        cout << "After sorting using bubble sort algorithm:" << endl;
        bubblesort(arr, n);
        break;
        case 3:
         cout << "After sorting using insertion sort algorithm:" << endl;
        insertionsort(arr, n);
        break;
        case 4:
        cout << "After sorting using quicksort algorithm:" << endl;
        quicksort(arr, 0, n-1);
        break;
        case 5:
        cout << "After sorting using merge sort algorithm:" << endl;
        merge(arr, 0, n-1);
        break;
        case 6:

        cout << "After sorting using heap sort algorithm:" << endl;
        heapSort(arr,n);
        break;
        default:
        cout << "Invalid input! Please enter between 1 and 6." << endl;
        
    }
    return 0;
}
