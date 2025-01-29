//
//  main.cpp
//  ReverseLL
//
//  Created by Prashant on 28/01/25.
//

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* reverseLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

Node* kReversal(Node* head, int k){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    int count = 0;
    
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != nullptr) {
        head->next = kReversal(next, k);
    }
    return prev;
}
