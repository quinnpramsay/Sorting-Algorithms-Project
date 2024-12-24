#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Partition function
void partition(int arr[], int low, int high, int& pivotpoint, int& partition_count, int& compare_count, int& swap_count) { 
    int j = low;               // Set j to low
    int pivotItem = arr[low];   // Set pivot item to arr[low]

    partition_count++;          // Increase partition count
    for (int i = low + 1; i <= high; i++) {
        compare_count++;        // Increase comparison count
        if (arr[i] < pivotItem) {
            swap_count++;       // Increase swap count
            j++;
            swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
        }
    }
    pivotpoint = j;  
    swap(arr[low], arr[pivotpoint]); // Swap pivotpoint and arr[low]
}

// Quicksort function
void quicksort(int arr[], int low, int high, int& quicksort_count, int& partition_count, int& total_count, int& compare_count, int& swap_count) {
    quicksort_count++;          // Increase quicksort count
    total_count = quicksort_count + partition_count; // Update total count

    if (high > low) {
        int pivotpoint;
        partition(arr, low, high, pivotpoint, partition_count, compare_count, swap_count);
        quicksort(arr, low, pivotpoint - 1, quicksort_count, partition_count, total_count, compare_count, swap_count);
        quicksort(arr, pivotpoint + 1, high, quicksort_count, partition_count, total_count, compare_count, swap_count);
    }
}

int main() {
    // Correct array initialization
    int arr[] = {10, 30, 40, 40, 20, 50, 20, 10, 10, 20, 50, 10, 40, 50, 30, 30, 30, 20, 10, 10, 30, 40, 50, 50, 50, 50, 40, 30, 50, 20, 10, 30, 10, 30, 50, 50, 20, 50, 40, 50, 20, 30, 30, 30, 50, 40, 10, 20, 30, 30, 40, 20, 10, 10, 50, 10, 30, 30, 40, 40, 50, 20, 40, 50, 30, 40, 30, 50, 30, 50, 10, 40, 30, 30, 50, 30, 30, 40, 40, 40, 30, 10, 20, 10, 50, 10, 50, 20, 40, 40, 20, 50, 30, 30, 20, 30, 40, 30, 40, 50, 10, 10, 10, 20, 20, 30, 30, 40, 40, 20, 10, 40, 10, 30, 20, 20, 40, 30, 40, 10, 20, 10, 10, 20, 50, 30, 50, 30, 30, 30, 40, 50, 40, 50, 10, 30, 40, 30, 50, 50, 10, 50, 50, 10, 20, 30, 20, 20, 20, 20, 50, 40, 10, 20, 50, 30, 10, 50, 20, 30, 30, 20, 20, 10, 40, 50, 30, 10, 20, 10, 10, 30, 40, 10, 30, 20, 40, 50, 20, 50, 10, 30, 50, 10, 50, 10, 50, 30, 10, 40, 30, 40, 10, 30, 30, 50, 50, 10, 30, 10, 50, 40, 50, 10, 30, 20, 50, 20, 20, 20, 20, 40, 20, 10, 20, 10, 20, 10, 20, 10, 50, 50, 10, 40, 40, 50, 50, 20, 20, 40, 20, 20, 50, 20, 10, 40, 30, 50, 20, 50, 10, 10, 50, 20, 20, 20, 20, 50, 40, 10, 40, 50, 40, 50, 50, 30, 30, 50, 50, 40, 10, 50, 30, 30, 30, 20, 20, 50, 50, 10, 50, 10, 30, 30, 40, 30, 20, 10, 30, 10, 20, 50, 30, 20, 10, 30, 50, 40, 50, 20, 30, 30, 50, 50, 20, 20, 30, 20, 40, 30, 10, 30, 40, 30, 40, 20, 40, 20, 40, 40, 10, 30, 40, 10, 10, 20, 50, 10, 30, 20, 20, 30, 10, 10, 40, 30, 30, 20, 40, 50, 10, 50, 50, 30, 40, 30, 20, 30, 20, 50, 10, 30, 40, 30, 10, 30, 10, 20, 20, 20, 10, 40, 30, 20, 30, 30, 20, 50, 20, 10, 40, 10, 30, 20, 30, 40, 50, 10, 20, 40, 20, 50, 30, 30, 40, 10, 10, 40, 30, 30, 40, 30, 10, 50, 40, 40, 20, 10, 50, 50, 20, 40, 50, 50, 30, 40, 30, 20, 10, 20, 50, 20, 50, 30, 30, 10, 10, 10, 20, 10, 20, 40, 50, 10, 40, 40, 30, 30, 30, 40, 30, 30, 30, 10, 50, 10, 40, 30, 30, 40, 20, 20, 50, 50, 20, 10, 40, 30, 20, 30, 10, 50, 40, 10, 30, 50, 10, 20, 30, 20, 40, 50, 30, 10, 20, 30, 20, 20, 30, 20, 50, 50, 10, 50, 30, 50, 20, 30, 30, 40, 50, 50, 30, 30, 20, 20, 30, 40, 50, 50, 30, 30, 10, 30, 30, 40, 30, 30, 10, 20, 50, 50, 10, 20, 50, 30, 50, 40, 50, 10, 10, 30, 50, 50, 20, 50, 30, 50, 10, 30, 30, 40, 20, 50, 20, 50, 40, 10, 10, 30, 40, 30, 10, 10, 40, 20, 50, 30, 10, 10, 20, 30, 50, 50, 10, 10, 30, 10, 20, 30, 10, 10, 30, 30, 50, 40, 30, 40, 50, 50, 10, 50, 10, 50, 10, 40, 50, 30, 30, 10, 50, 40, 10, 10, 40, 20, 30, 50, 30, 10, 10, 10, 30, 30, 10, 20, 20, 30, 50, 10, 10, 20, 50, 10, 30, 50, 30, 40, 50, 40, 50, 10, 30, 30, 20, 50, 10, 20, 20, 30, 50, 50, 30, 40, 20, 40, 20, 50, 10, 10, 40, 20, 10, 30, 40, 40, 50, 20, 50, 50, 40, 10, 30, 40, 20, 20, 30, 10, 50, 10, 30, 50, 10, 20, 10, 40, 40, 40, 20, 40, 30, 20, 40, 10, 50, 10, 30, 40, 20, 30, 40, 10, 30, 40, 20, 40, 10, 40, 30, 10, 30, 50, 40, 20, 20, 40, 50, 20, 30, 20, 20, 50, 10, 50, 10, 20, 20, 10, 50, 40, 30, 30, 20, 50, 20, 20, 20, 40, 10, 40, 40, 30, 50, 10, 20, 20, 30, 50, 40, 10, 30, 20, 10, 10, 20, 50, 10, 40, 20, 10, 30, 20, 20, 50, 20, 20, 40, 10, 50, 40, 20, 20, 30, 40, 40, 40, 20, 30, 30, 50, 20, 30, 20, 10, 50, 30, 10, 30, 30, 10, 50, 40, 30, 50, 10, 30, 20, 30, 10, 10, 30, 20, 30, 20, 20, 30, 10, 30, 50, 50, 50, 10, 40, 50, 50, 50, 10, 40, 50, 30, 40, 30, 50, 20, 20, 20, 50, 10, 30, 20, 30, 30, 20, 30, 10, 50, 20, 20, 30, 50, 30, 30, 50, 10, 10, 30, 40, 50, 50, 50, 10, 30, 20, 20, 10, 10, 20, 20, 40, 20, 20, 20, 20, 40, 40, 50, 40, 20, 10, 40, 20, 10, 50, 40, 30, 20, 10, 50, 30, 10, 10, 20, 20, 40, 50, 50, 50, 40, 30, 20, 40, 50, 20, 30, 30, 40, 10, 10, 20, 10, 50, 40, 10, 20, 10, 10, 50, 40, 30, 20, 30, 40, 20, 10, 10, 10, 50, 30, 20, 50, 20, 40, 30, 40, 30, 30, 10, 50, 50, 20, 10, 40, 30, 10, 20, 20, 20, 10, 20, 10, 50, 10, 10, 40, 40, 50, 50, 50, 10, 40, 30, 20, 50, 30, 50, 30, 10, 50, 50, 50, 40, 40, 40, 40, 20, 10, 10, 30, 40, 10, 50, 10, 50, 50, 40, 50, 50, 30, 20, 50, 30, 40, 20, 30, 40, 50, 10, 50, 40, 30, 30, 10, 20, 10, 30, 40, 50, 40, 20, 30, 20, 50, 30, 10, 10, 20, 50, 10, 10, 30, 50, 20, 20, 10, 30, 10, 30, 30, 30, 20, 40, 20, 10, 30, 10, 40, 50, 50, 10, 20, 50, 40, 20, 30, 10, 50, 30, 30, 10, 50, 30, 30, 30, 20, 50, 50, 30, 20, 40, 30};

    int n = sizeof(arr) / sizeof(arr[0]); // Get array size

    // Set counters to 0
    int quicksort_count = 0;
    int partition_count = 0;
    int total_count = 0;
    int compare_count = 0;
    int swap_count = 0;

    // Start timer
    auto start = high_resolution_clock::now();

    // Run quicksort
    quicksort(arr, 0, n - 1, quicksort_count, partition_count, total_count, compare_count, swap_count);

    // Stop timer
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print performance stats
    cout << "Total Comparisons = " << compare_count << endl;
    cout << "Total Swaps = " << swap_count << endl;
    cout << "Time taken = " << duration << " microseconds" << endl;

    return 0;
}
