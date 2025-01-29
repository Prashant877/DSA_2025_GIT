//
//  main.cpp
//  Recursion
//
//  Created by Prashant on 24/01/25.
//

#include <iostream>
using namespace std;

void reachDest(int start, int end){
    //base case
    if(start == end){
        cout<<"Destination reached";
        return;
    }
    start++;
    
    reachDest(start, end);
}

int sol(int n) {
    // Base case: Any number to the power of 0 is 1.
    if (n == 0) {
        return 1;
    }
    // Recursive relation: 2^n = 2 * 2^(n-1)
    return 2 * sol(n - 1);
}

int factorial(int n) {
    // Base case: 0! = 1 and 1! = 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive relation: n! = n * (n-1)!
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    // Base case: F(0) = 0, F(1) = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Recursive relation: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int climbStairs(int n) {
    // Base cases:
    if (n == 0) return 1; // 1 way to stay at step 0 (do nothing)
    if (n == 1) return 1; // 1 way to climb 1 step (1 step)

    // Recursive relation: Total ways = Ways to climb (n-1) + Ways to climb (n-2)
    return climbStairs(n - 1) + climbStairs(n - 2);
}

bool isSorted(int arr[], int size){
    if(size == 0 || size == 1) return true;
    if(arr[0] > arr[1]){
        return false;
    }
    else{
        return isSorted(arr+1,size-1);
    }
}

int sumArray(int arr[], int n) {
    // Base case: If the array is empty (n = 0), the sum is 0
    if (n == 0) {
        return 0;
    }

    // Recursive relation: Sum of the array is the last element + sum of the rest
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main(){
    cout<<climbStairs(5)<<endl;
}
