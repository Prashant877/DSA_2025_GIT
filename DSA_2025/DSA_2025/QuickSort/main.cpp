//
//  main.cpp
//  QuickSort
//
//  Created by Prashant on 25/01/25.
//
/*
#include <iostream>
using namespace std;

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // If current element is smaller than or equal to pivot
            i++;               // Increment the index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    // Place the pivot in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the pivot index
}

// Quick Sort Function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort the left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
*/
#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    // Find the pivot element -> first element
    int pivot = arr[s];

    // Counting how many elements are less than pivot
    int count = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Place pivot in its correct position
    int pivotIdx = s + count;
    swap(arr[s], arr[pivotIdx]);  // Swap pivot to the correct position

    // Now, we'll handle the right and left parts in which all elements should be less and greater, respectively.
    int i = s, j = e;

    // Start two pointers from the left and right ends of the array
    while (i < pivotIdx && j > pivotIdx) {
        while (arr[i] < pivot) i++;    // Move i to the right until we find an element >= pivot
        while (arr[j] > pivot) j--;    // Move j to the left until we find an element <= pivot

        if (i < pivotIdx && j > pivotIdx) {
            swap(arr[i++], arr[j--]); // Swap the elements if valid indices
        }
    }

    return pivotIdx;
}

void quickSort(int arr[], int s, int e) {
    // Base case: when the subarray has one or zero elements
    if (s >= e) return;

    // Partition the array, and get the pivot index
    int p = partition(arr, s, e);

    // Recursively sort the left and right parts
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[5] = {2, 1, 7, 3, 5};
    int n = 5;

    // Sorting the array using quick sort
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

