//
//  main.cpp
//  SelectionSort
//
//  Created by Prashant on 23/01/25.
//

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Loop through the array
        int minIdx = i; // Assume the current index is the smallest
        
        for (int j = i + 1; j < n; j++) { // Find the smallest element
            if (arr[j] < arr[minIdx]) {
                minIdx = j; // Update the index of the smallest element
            }
        }
        // Swap the smallest element with the current element
        swap(arr[minIdx], arr[i]);
    }
}

int main() {
    int arr[6] = {4, 2, 6, 8, 7, 3}; // Array to sort
    selectionSort(arr, 6); // Call the selection sort function

    // Print the sorted array
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
