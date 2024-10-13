// Importing libraries
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

/* FUNCTION DECLARATIONS */
void merge_sort(vector<int>& arr, int left, int right);
void bubble_sort(vector<int>& arr);
void analyze_sorting(const vector<int>& delivery_times, bool displayArray = true);

/* MAIN PROGRAM */
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    int choice;
    cout << "Choose an option (1 or 2):" << endl;
    cout << "1. Input numbers manually" << endl;
    cout << "2. Generate arrays of sizes 500, 5000, and 15000 with random numbers" << endl;
    cin >> choice;

    if (choice == 1) {
        int N;
        cout << "Enter the number of deliveries: ";
        cin >> N;

        vector<int> delivery_times(N);
        cout << "Enter the delivery times:" << endl;
        for (int i = 0; i < N; ++i) {
            cout << "Enter delivery time " << (i + 1) << ": ";
            cin >> delivery_times[i];
        }

        analyze_sorting(delivery_times);
    } else if (choice == 2) {
        vector<int> sizes = {500, 5000, 15000};
        for (int size : sizes) {
            vector<int> delivery_times(size);
            for (int i = 0; i < size; ++i) {
                delivery_times[i] = rand() % 99 + 1; // Random numbers between 1 and 99
            }

            cout << "Analyzing array of size " << size << ":" << endl;
            analyze_sorting(delivery_times, false); // Do not display sorted arrays
            cout << endl;
        }
    } else {
        cout << "Invalid choice. Please run the program again and choose 1 or 2." << endl;
    }

    return 0;
}

/* FUNCTION DEFINITIONS */

// Function: Bubble Sort - n^2
void bubble_sort(vector<int>& arr) {
    int n = arr.size(); // O(1)
    for (int i = 0; i < n - 1; ++i) { // O(n) 
        for (int j = 0; j < n - i - 1; ++j) { // O(n) 
            if (arr[j] > arr[j + 1]) { // O(1) 
                swap(arr[j], arr[j + 1]); // O(1) 
            }
        }
    }
}

// Function: Merge two sorted subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // O(1) 
    int n2 = right - mid; // O(1) 
    vector<int> L(n1), R(n2); // O(n1 + n2) 

    for (int i = 0; i < n1; ++i) // O(n1)
        L[i] = arr[left + i]; // O(1) 

    for (int j = 0; j < n2; ++j) // O(n2) 
        R[j] = arr[mid + 1 + j]; // O(1) 

    int i = 0, j = 0, k = left; // O(1) 

    while (i < n1 && j < n2) { // O(n1 + n2) 
        if (L[i] <= R[j]) { // O(1) 
            arr[k++] = L[i++]; // O(1) 
        } else {
            arr[k++] = R[j++]; // O(1) 
        }
    }

    while (i < n1) { // O(n1) 
        arr[k++] = L[i++]; // O(1) 
    }

    while (j < n2) { // O(n2) 
        arr[k++] = R[j++]; // O(1) 
    }
}

// Function: Merge Sort - O(n log n)
void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) { // O(1) 
        int mid = left + (right - left) / 2; // O(1) 
        merge_sort(arr, left, mid); // O(log n) 
        merge_sort(arr, mid + 1, right); // O(log n) 
        merge(arr, left, mid, right); // O(n) 
    }
}

// Function: Analyze and compare sorting algorithms
void analyze_sorting(const vector<int>& delivery_times, bool displayArray) {
    // Bubble Sort
    vector<int> bubbleSortedTimes = delivery_times;
    auto startBubble = chrono::high_resolution_clock::now();
    bubble_sort(bubbleSortedTimes);
    auto endBubble = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> bubbleDuration = endBubble - startBubble;

    // Merge Sort
    vector<int> mergeSortedTimes = delivery_times;
    auto startMerge = chrono::high_resolution_clock::now();
    merge_sort(mergeSortedTimes, 0, mergeSortedTimes.size() - 1);
    auto endMerge = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> mergeDuration = endMerge - startMerge;

    // Print durations and optionally sorted arrays in milliseconds
    if (displayArray) {
        cout << "Bubble Sorted Array: ";
        for (const auto& val : bubbleSortedTimes) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Bubble Sort duration: " << bubbleDuration.count() << " ms" << endl;

    if (displayArray) {
        cout << "Merge Sorted Array: ";
        for (const auto& val : mergeSortedTimes) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Merge Sort duration: " << mergeDuration.count() << " ms" << endl;
}