//
//  main.cpp
//  CircularLL
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

void insertAtHead(Node* &head,int val){
    Node* n = new Node(val);
    Node* temp = head;
    
    if(head == NULL){
        n->next = head;
        head = n;
        return;
    }
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(Node* &head,int val){
    Node* n = new Node(val);
    Node* temp = head;
    
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deleteAtHead(Node* &head){
    Node* temp = head;
    
    while(temp->next != head){
        temp = temp->next;
    }
    
    Node* del = head;
    temp->next = head->next;
    head = head->next;
    
    delete del;
}

void deletion(Node* &head){
    
}

int main(){
    Node* head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtTail(head,4);
    insertAtTail(head,5);
   // display(head);
}
