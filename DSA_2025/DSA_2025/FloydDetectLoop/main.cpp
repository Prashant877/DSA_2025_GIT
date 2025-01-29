//
//  main.cpp
//  FloydDetectLoop
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

Node* floydDetectLoop(Node* &head){
    if(head == NULL) return NULL;
        
    Node* fast = NULL;
    Node* slow = NULL;
    
    while(slow != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) return slow;
    }
    return NULL;
}

Node* getStartingNode(Node* &head){
    if(head == NULL) return NULL;
    
    Node* intersection = floydDetectLoop(head);
    Node* slow = head;
    
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeLoop(Node* &head){
    if(head == NULL) return;
    
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;
    
    while(temp->next != startOfLoop){
        temp = temp->next;
    }
    temp->next = NULL;
    
}

int main(){
    
}
