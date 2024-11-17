#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
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
    
    cout << "Quick Sort Timing (ms)" << endl;
    cout << "Array Size     Best     Avg     Worst" << endl;
    for (int size : sizes) {
        long long bestTime = measureTime(generateArray(size, "random"));
        long long avgTime = measureTime(generateArray(size, "reverse"));
        long long worstTime = measureTime(generateArray(size, "sorted"));
        cout << setw(8) << size << setw(10) << bestTime << setw(10) << avgTime << setw(10) << worstTime << endl;
    }
    return 0;
}
