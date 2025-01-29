//
//  main.cpp
//  MergeSort
//
//  Created by Prashant on 23/01/25.
//

#include <iostream>
using namespace std;

void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge both arrays while elements remain in both
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Add remaining elements of arr1 (if any)
    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    // Add remaining elements of arr2 (if any)
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create an array to store the merged result
    int merged[n1 + n2];

    // Merge the two arrays
    mergeSortedArrays(arr1, n1, arr2, n2, merged);

    // Print the merged array
    for (int i = 0; i < n1 + n2; i++) {
        cout << merged[i] << " ";
    }

    return 0;
}
/*
 #include <iostream>
 #include <vector>
 using namespace std;

 void merge(vector<int>& arr, int s, int mid, int e) {
     vector<int> temp;

     int i = s;       // Start of the first half
     int j = mid + 1; // Start of the second half

     // Merge the two halves into the temp array
     while (i <= mid && j <= e) {
         if (arr[i] <= arr[j]) {
             temp.push_back(arr[i++]);
         } else {
             temp.push_back(arr[j++]);
         }
     }

     // Copy remaining elements from the first half
     while (i <= mid) {
         temp.push_back(arr[i++]);
     }

     // Copy remaining elements from the second half
     while (j <= e) {
         temp.push_back(arr[j++]);
     }

     // Copy sorted elements back into the original array
     for (int k = s; k <= e; k++) {
         arr[k] = temp[k - s];
     }
 }

 void mergeSortMethod(vector<int>& arr, int s, int e) {
     if (s >= e) return;

     int mid = (s + e) / 2;

     // Recursively divide the array
     mergeSortMethod(arr, s, mid);
     mergeSortMethod(arr, mid + 1, e);

     // Merge the two sorted halves
     merge(arr, s, mid, e);
 }

 void mergeSort(vector<int>& arr, int n) {
     mergeSortMethod(arr, 0, n - 1);
 }

 int main() {
     int n;
     cout << "Enter the size of the array: ";
     cin >> n;

     vector<int> arr(n);
     cout << "Enter " << n << " elements: ";
     for (int i = 0; i < n; i++) {
         cin >> arr[i];
     }

     mergeSort(arr, n);

     cout << "Sorted array: ";
     for (int i = 0; i < n; i++) {
         cout << arr[i] << " ";
     }
     cout << endl;

     return 0;
 }
 */
