//
//  main.cpp
//  Palindrome
//
//  Created by Prashant on 25/01/25.
//

#include <iostream>
using namespace std;

bool isValid(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <='Z') || (ch >= '0' && ch <= '9')){
        return true;
    }
    return false;
}

char toLower(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return true;
    }
    else {
        char temp = ch - 'A' + 'a'; //also ch + 32 if u wanted to use constant
        return temp;
    }
}

bool checkPalindrome(char arr[], int size){
    int start = 0;
    int end = size - 1;
    
    while(start <= end){
        if(arr[start] != arr[end]){
            return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}

