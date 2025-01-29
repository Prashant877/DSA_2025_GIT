//
//  main.cpp
//  2D_Array
//
//  Created by Prashant on 22/01/25.
//

#include <iostream>
#include <climits>
using namespace std;

// Function to take input for a 2D array
void input2DArray(int arr[][4], int rows, int cols) {
    cout << "Enter the elements of the array row by row:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
}

// Function to check if an element is present in the 2D array
bool isPresent(int arr[][4], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == key) {
                return true;
            }
        }
    }
    return false;
}

// Function to calculate the sum of all elements in the 2D array
int sumOfArray(int arr[][4], int rows, int cols) {
    int sum = 0; // Local sum variable
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

// Function to find the row with the maximum sum
int findRowWithMaxSum(int arr[][4], int rows, int cols) {
    int maxSum = INT_MIN; // To track the maximum row sum
    int rowIndex = -1;    // To store the row index with the maximum sum

    for (int i = 0; i < rows; i++) {
        int currentSum = 0;

        // Calculate the sum of the current row
        for (int j = 0; j < cols; j++) {
            currentSum += arr[i][j];
        }

        // Update maximum sum and row index if needed
        if (currentSum > maxSum) {
            maxSum = currentSum;
            rowIndex = i;
        }
    }

    return rowIndex;
}

// Function to print a 2D array in wave pattern
void printWavePattern(int arr[][4], int rows, int cols) {
    cout << "Wave Pattern: ";
    for (int col = 0; col < cols; col++) {
        // Even column: Top to Bottom
        if (col % 2 == 0) {
            for (int row = 0; row < rows; row++) {
                cout << arr[row][col] << " ";
            }
        }
        // Odd column: Bottom to Top
        else {
            for (int row = rows - 1; row >= 0; row--) {
                cout << arr[row][col] << " ";
            }
        }
    }
    cout << endl;
}

// Function to print a 2D array in spiral order
void printSpiral(int arr[][4], int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    cout << "Spiral Order: ";

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; i++) {
            cout << arr[top][i] << " ";
        }
        top++;

        // Traverse from top to bottom along the rightmost column
        for (int i = top; i <= bottom; i++) {
            cout << arr[i][right] << " ";
        }
        right--;

        // Traverse from right to left along the bottom row (if applicable)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }

        // Traverse from bottom to top along the leftmost column (if applicable)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

// Main function
int main() {
    int rows = 3, cols = 4;
    int arr[3][4];

    // Take input for the 2D array
    input2DArray(arr, rows, cols);

    // Search for a key in the 2D array
    int key;
    cout << "Enter the key to search in the array: ";
    cin >> key;

    if (isPresent(arr, rows, cols, key)) {
        cout << "Key " << key << " is present in the array." << endl;
    } else {
        cout << "Key " << key << " is not present in the array." << endl;
    }

    // Calculate and display the sum of all elements
    int totalSum = sumOfArray(arr, rows, cols);
    cout << "Sum of all elements in the array: " << totalSum << endl;

    // Find and display the row with the maximum sum
    int rowWithMaxSum = findRowWithMaxSum(arr, rows, cols);
    cout << "Row with the maximum sum is: " << rowWithMaxSum << endl;

    // Print the 2D array in wave pattern
    printWavePattern(arr, rows, cols);
    
    // Print the array in spiral order
    printSpiral(arr, rows, cols);

    return 0;
}
