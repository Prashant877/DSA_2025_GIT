//
//  main.cpp
//  InsertionSort
//
//  Created by Prashant on 25/01/25.
//

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 0; i <= n-1; i++){
        int j = i;
        
        while(j > 0 && arr[j-1] > arr[j]){
            //swap(arr[j-1],arr[j]);
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
#include <iostream>
using namespace std;

/*void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {  // Start from the second element
        int key = arr[i];          // Current element to be placed
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;          // Place the key in the correct position
    }
}*/

int main() {
    int n;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // Input the array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array
    insertionSort(arr, n);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
