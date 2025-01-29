//
//  main.cpp
//  BubbleSort
//
//  Created by Prashant on 23/01/25.
//

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool hasSwapped = false; // Variable to track if any swapping occurred
        for (int j = 0; j < n - i - 1; j++) { // Fixed condition to avoid out-of-bounds access
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                hasSwapped = true;
            }
        }
        // If no elements were swapped, the array is already sorted
        if (!hasSwapped) {
            break;
        }
    }
}

int main() {
    int arr[6] = {4, 2, 6, 8, 7, 3}; // Array to sort

    bubbleSort(arr, 6); // Call the bubbleSort function

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " "; // Print the sorted array
    }

    return 0;
}
