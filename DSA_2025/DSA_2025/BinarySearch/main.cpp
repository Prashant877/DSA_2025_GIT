//
//  main.cpp
//  BinarySearch
//
//  Created by Prashant on 20/01/25.
//

#include <iostream>
using namespace std;

int binarySearch(int arr[],int size,int key){
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;
    
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if (arr[mid]<key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = (start+end)/2;
    }
    return -1;
}
int main(){
    int arr[7] = {0,2,4,6,7,8,9};
    int ans = binarySearch(arr,7,8);
    cout<<"Key found at the index: "<<ans<<endl;
}
