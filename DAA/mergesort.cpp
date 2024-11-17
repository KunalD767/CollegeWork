#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, arr.size() - 1);
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
    
    cout << "Merge Sort Timing (ms)" << endl;
    cout << "Array Size     Best     Avg     Worst" << endl;
    for (int size : sizes) {
        long long bestTime = measureTime(generateArray(size, "sorted"));
        long long avgTime = measureTime(generateArray(size, "random"));
        long long worstTime = measureTime(generateArray(size, "reverse"));
        cout << setw(8) << size << setw(10) << bestTime << setw(10) << avgTime << setw(10) << worstTime << endl;
    }
    return 0;
}
