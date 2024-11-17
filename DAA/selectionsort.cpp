#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
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
    selectionSort(arr);
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

    cout << "Selection Sort Timing (ms)" << endl;
    cout << "Array Size     Best     Avg     Worst" << endl;
    for (int size : sizes) {
        long long bestTime = measureTime(generateArray(size, "sorted"));
        long long avgTime = measureTime(generateArray(size, "random"));
        long long worstTime = measureTime(generateArray(size, "reverse"));
        cout << setw(8) << size << setw(10) << bestTime << setw(10) << avgTime << setw(10) << worstTime << endl;
    }
    return 0;
}
