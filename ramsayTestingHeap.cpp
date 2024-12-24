#include <iostream>
#include <cmath>
#include <chrono>  
using namespace std;
using namespace std::chrono;  

// Heap Struct
struct heap {
    int S[1000];      // S is indexed from 0 to (n-1)
    int heapsize;  // heapsize only takes values 0 to n
};

void siftdown(heap& H, int i, int& compare_count, int& swap_count);
int root(heap& H, int& compare_count, int& swap_count);
void removekeys(int n, heap& H, int S[], int& compare_count, int& swap_count);
void makeheap(int n, heap& H, int& compare_count, int& swap_count);
void heapsort(int n, heap& H, int& compare_count, int& swap_count);

// Main Function
int main() {
    // Variables
    heap H = {{10, 30, 40, 40, 20, 50, 20, 10, 10, 20, 50, 10, 40, 50, 30, 30, 30, 20, 10, 10, 30, 40, 50, 50, 50, 50, 40, 30, 50, 20, 10, 30, 10, 30, 50, 50, 20, 50, 40, 50, 20, 30, 30, 30, 50, 40, 10, 20, 30, 30, 40, 20, 10, 10, 50, 10, 30, 30, 40, 40, 50, 20, 40, 50, 30, 40, 30, 50, 30, 50, 10, 40, 30, 30, 50, 30, 30, 40, 40, 40, 30, 10, 20, 10, 50, 10, 50, 20, 40, 40, 20, 50, 30, 30, 20, 30, 40, 30, 40, 50, 10, 10, 10, 20, 20, 30, 30, 40, 40, 20, 10, 40, 10, 30, 20, 20, 40, 30, 40, 10, 20, 10, 10, 20, 50, 30, 50, 30, 30, 30, 40, 50, 40, 50, 10, 30, 40, 30, 50, 50, 10, 50, 50, 10, 20, 30, 20, 20, 20, 20, 50, 40, 10, 20, 50, 30, 10, 50, 20, 30, 30, 20, 20, 10, 40, 50, 30, 10, 20, 10, 10, 30, 40, 10, 30, 20, 40, 50, 20, 50, 10, 30, 50, 10, 50, 10, 50, 30, 10, 40, 30, 40, 10, 30, 30, 50, 50, 10, 30, 10, 50, 40, 50, 10, 30, 20, 50, 20, 20, 20, 20, 40, 20, 10, 20, 10, 20, 10, 20, 10, 50, 50, 10, 40, 40, 50, 50, 20, 20, 40, 20, 20, 50, 20, 10, 40, 30, 50, 20, 50, 10, 10, 50, 20, 20, 20, 20, 50, 40, 10, 40, 50, 40, 50, 50, 30, 30, 50, 50, 40, 10, 50, 30, 30, 30, 20, 20, 50, 50, 10, 50, 10, 30, 30, 40, 30, 20, 10, 30, 10, 20, 50, 30, 20, 10, 30, 50, 40, 50, 20, 30, 30, 50, 50, 20, 20, 30, 20, 40, 30, 10, 30, 40, 30, 40, 20, 40, 20, 40, 40, 10, 30, 40, 10, 10, 20, 50, 10, 30, 20, 20, 30, 10, 10, 40, 30, 30, 20, 40, 50, 10, 50, 50, 30, 40, 30, 20, 30, 20, 50, 10, 30, 40, 30, 10, 30, 10, 20, 20, 20, 10, 40, 30, 20, 30, 30, 20, 50, 20, 10, 40, 10, 30, 20, 30, 40, 50, 10, 20, 40, 20, 50, 30, 30, 40, 10, 10, 40, 30, 30, 40, 30, 10, 50, 40, 40, 20, 10, 50, 50, 20, 40, 50, 50, 30, 40, 30, 20, 10, 20, 50, 20, 50, 30, 30, 10, 10, 10, 20, 10, 20, 40, 50, 10, 40, 40, 30, 30, 30, 40, 30, 30, 30, 10, 50, 10, 40, 30, 30, 40, 20, 20, 50, 50, 20, 10, 40, 30, 20, 30, 10, 50, 40, 10, 30, 50, 10, 20, 30, 20, 40, 50, 30, 10, 20, 30, 20, 20, 30, 20, 50, 50, 10, 50, 30, 50, 20, 30, 30, 40, 50, 50, 30, 30, 20, 20, 30, 40, 50, 50, 30, 30, 10, 30, 30, 40, 30, 30, 10, 20, 50, 50, 10, 20, 50, 30, 50, 40, 50, 10, 10, 30, 50, 50, 20, 50, 30, 50, 10, 30, 30, 40, 20, 50, 20, 50, 40, 10, 10, 30, 40, 30, 10, 10, 40, 20, 50, 30, 10, 10, 20, 30, 50, 50, 10, 10, 30, 10, 20, 30, 10, 10, 30, 30, 50, 40, 30, 40, 50, 50, 10, 50, 10, 50, 10, 40, 50, 30, 30, 10, 50, 40, 10, 10, 40, 20, 30, 50, 30, 10, 10, 10, 30, 30, 10, 20, 20, 30, 50, 10, 10, 20, 50, 10, 30, 50, 30, 40, 50, 40, 50, 10, 30, 30, 20, 50, 10, 20, 20, 30, 50, 50, 30, 40, 20, 40, 20, 50, 10, 10, 40, 20, 10, 30, 40, 40, 50, 20, 50, 50, 40, 10, 30, 40, 20, 20, 30, 10, 50, 10, 30, 50, 10, 20, 10, 40, 40, 40, 20, 40, 30, 20, 40, 10, 50, 10, 30, 40, 20, 30, 40, 10, 30, 40, 20, 40, 10, 40, 30, 10, 30, 50, 40, 20, 20, 40, 50, 20, 30, 20, 20, 50, 10, 50, 10, 20, 20, 10, 50, 40, 30, 30, 20, 50, 20, 20, 20, 40, 10, 40, 40, 30, 50, 10, 20, 20, 30, 50, 40, 10, 30, 20, 10, 10, 20, 50, 10, 40, 20, 10, 30, 20, 20, 50, 20, 20, 40, 10, 50, 40, 20, 20, 30, 40, 40, 40, 20, 30, 30, 50, 20, 30, 20, 10, 50, 30, 10, 30, 30, 10, 50, 40, 30, 50, 10, 30, 20, 30, 10, 10, 30, 20, 30, 20, 20, 30, 10, 30, 50, 50, 50, 10, 40, 50, 50, 50, 10, 40, 50, 30, 40, 30, 50, 20, 20, 20, 50, 10, 30, 20, 30, 30, 20, 30, 10, 50, 20, 20, 30, 50, 30, 30, 50, 10, 10, 30, 40, 50, 50, 50, 10, 30, 20, 20, 10, 10, 20, 20, 40, 20, 20, 20, 20, 40, 40, 50, 40, 20, 10, 40, 20, 10, 50, 40, 30, 20, 10, 50, 30, 10, 10, 20, 20, 40, 50, 50, 50, 40, 30, 20, 40, 50, 20, 30, 30, 40, 10, 10, 20, 10, 50, 40, 10, 20, 10, 10, 50, 40, 30, 20, 30, 40, 20, 10, 10, 10, 50, 30, 20, 50, 20, 40, 30, 40, 30, 30, 10, 50, 50, 20, 10, 40, 30, 10, 20, 20, 20, 10, 20, 10, 50, 10, 10, 40, 40, 50, 50, 50, 10, 40, 30, 20, 50, 30, 50, 30, 10, 50, 50, 50, 40, 40, 40, 40, 20, 10, 10, 30, 40, 10, 50, 10, 50, 50, 40, 50, 50, 30, 20, 50, 30, 40, 20, 30, 40, 50, 10, 50, 40, 30, 30, 10, 20, 10, 30, 40, 50, 40, 20, 30, 20, 50, 30, 10, 10, 20, 50, 10, 10, 30, 50, 20, 20, 10, 30, 10, 30, 30, 30, 20, 40, 20, 10, 30, 10, 40, 50, 50, 10, 20, 50, 40, 20, 30, 10, 50, 30, 30, 10, 50, 30, 30, 30, 20, 50, 50, 30, 20, 40, 30}, 1000};  // Initialize heap with values and set heapsize
    int compare_count = 0, swap_count = 0;

    // Start measuring time
    auto start = high_resolution_clock::now();

    // Perform heapsort
    heapsort(1000, H, compare_count, swap_count);

    // End measuring time
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Output sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < 1000; i++) {
        cout << H.S[i] << " ";
    }
    cout << endl;

    // Output the number of comparisons and swaps
    cout << "Comparisons: " << compare_count << endl;
    cout << "Swaps: " << swap_count << endl;

    // Output the time taken
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}

// Function to sift down the heap and maintain heap property
void siftdown(heap& H, int i, int& compare_count, int& swap_count) {
    int parent = i, largerChild;
    int siftkey = H.S[i];
    bool spotfound = false;

    // While there are children in the heap
    while (2 * parent + 1 < H.heapsize && !spotfound) {
        int leftChild = 2 * parent + 1;
        int rightChild = leftChild + 1;

        compare_count++;
        // Choose the larger child
        if (rightChild < H.heapsize && H.S[leftChild] < H.S[rightChild]) {
            largerChild = rightChild;
        } else {
            largerChild = leftChild;
        }

        compare_count++;
        // If the siftkey is smaller than the larger child, swap them
        if (siftkey < H.S[largerChild]) {
            H.S[parent] = H.S[largerChild];
            parent = largerChild;
            swap_count++;
        } else {
            spotfound = true;
        }
    }
    H.S[parent] = siftkey;
}

// Function to extract the root of the heap (largest element) and re-heapify
int root(heap& H, int& compare_count, int& swap_count) {
    int keyout = H.S[0];  // Extract the root element
    H.S[0] = H.S[H.heapsize - 1];  // Move the last element to the root
    H.heapsize--;  // Reduce the size of the heap
    siftdown(H, 0, compare_count, swap_count);  // Re-heapify
    return keyout;
}

// Function to remove all keys and perform sorting
void removekeys(int n, heap& H, int S[], int& compare_count, int& swap_count) {
    for (int i = n - 1; i >= 0; i--) {
        S[i] = root(H, compare_count, swap_count);  // Extract max and place it in sorted position
    }
}

// Function to build the heap from an unsorted array
void makeheap(int n, heap& H, int& compare_count, int& swap_count) {
    H.heapsize = n;  // Initialize heap size

    // Build the heap (starting from the last parent node)
    for (int i = (n / 2) - 1; i >= 0; i--) {
        siftdown(H, i, compare_count, swap_count);  // Ensure the heap property is maintained
    }
}

// Heapsort function that sorts the array
void heapsort(int n, heap& H, int& compare_count, int& swap_count) {
    makeheap(n, H, compare_count, swap_count);  // First, build the heap
    removekeys(n, H, H.S, compare_count, swap_count);  // Then extract elements in sorted order
}
