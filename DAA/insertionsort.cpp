#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

vector<int> generateArray(int size, string type)
{
    vector<int> arr(size);
    if (type == "sorted")
    {
        for (int i = 0; i < size; i++)
            arr[i] = i;
    }
    else if (type == "reverse")
    {
        for (int i = 0; i < size; i++)
            arr[i] = size - i - 1;
    }
    else
    {
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 1000;
    }
    return arr;
}

long long measureTime(vector<int> arr)
{
    auto start = high_resolution_clock::now();
    insertionSort(arr);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count(); // Now measuring in microseconds
}

int main()
{
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

    cout << "Insertion Sort Timing (microseconds)" << endl;
    cout << "Array Size     Best        Avg        Worst" << endl;
    for (int size : sizes)
    {
        long long bestTime = measureTime(generateArray(size, "sorted"));
        long long avgTime = measureTime(generateArray(size, "random"));
        long long worstTime = measureTime(generateArray(size, "reverse"));
        cout << setw(8) << size << setw(12) << bestTime << setw(12) << avgTime << setw(12) << worstTime << endl;
    }
    return 0;
}
