//
//  main.cpp
//  Array
//
//  Created by Prashant on 20/01/25.
//

#include <iostream>
using namespace std;

/*int getMaxElement(int arr[], int size){
int max = INT_MIN;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}*/
void reverseArray(int arr[],int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

int main(){
    //Array Declaration
    //int arr1[5];
    
    //Array Initialization
    //int arr1[5] = {5,7,9,1,2};
    //arr1[4] = 8;
    
    /*for(int i=0;i<5;i++){
     cout<<arr1[i]<<" ";
     }*/
    /*for(int i:arr1){
     cout<<i<<" ";
     }*/
    //Q. Take input from user of 5 numbers, store them in an array and print the numbers.
    /*int n = 5;
     int arr1[n];
     cout<<"Enter numbers: "<<endl;
     for(int i=0;i<=n-1;i++){
     cin>>arr1[i];
     };
     cout<<"Entered Numbers are: "<<endl;
     for(int i=0;i<=n-1;i++){
     cout<<arr1[i]<<" ";
     }
     cout<<endl;*/
    //int arr2[6] = {3,5,2,7,8,1};
    //int size = 6;
    //cout<<getMaxElement(arr2,6);
    int arr[6] = {2,4,7,8,5,6};
    reverseArray(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}
