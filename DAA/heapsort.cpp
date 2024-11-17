#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;  
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

vector<int> generateArray(int size, string type) {
    vector<int> arr(size);
    if (type == "sorted") {
        for (int i = 0; i < size; i++) arr[i] = i;
    } else if (type == "reverse") {
        for (int i = 0; i < size; i++) arr[i] = size - i - 1;
    } else {
        for (int i = 0; i < size; i++) arr[i] = rand() % 1000;
    }
    return arr;
}

long long measureTime(vector<int> arr) {
    auto start = high_resolution_clock::now();
    heapSort(arr);
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();  // Measuring time in microseconds
}

int main() {
    vector<int> sizes;
    sizes.push_back(10000);
    sizes.push_back(12000);
    sizes.push_back(14000);
    sizes.push_back(16000);
    sizes.push_back(18000);
    sizes.push_back(20000);
    sizes.push_back(22000);
    sizes.push_back(24000);
    sizes.push_back(26000);
    sizes.push_back(28000);
    cout << "Heap Sort Timing (microseconds)" << endl;
    cout << "Array Size     Best        Avg        Worst" << endl;
    for (int size : sizes) {
        long long bestTime = measureTime(generateArray(size, "sorted"));
        long long avgTime = measureTime(generateArray(size, "random"));
        long long worstTime = measureTime(generateArray(size, "reverse"));
        cout << setw(8) << size << setw(12) << bestTime << setw(12) << avgTime << setw(12) << worstTime << endl;
    }
    return 0;
}
