//
//  main.cpp
//  RemoveDuplicatesFromSorted
//
//  Created by Prashant on 29/01/25.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to remove duplicates from a sorted linked list
Node* RemoveDuplicatesFromSorted(Node* head) {
    if (head == NULL) return NULL;
    
    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            // Duplicate found, delete the next node
            Node* duplicateNode = temp->next;
            temp->next = temp->next->next; // Skip the duplicate
            delete duplicateNode; // Free memory
        } else {
            // Move to the next node if no duplicate
            temp = temp->next;
        }
    }

    return head;
}

// Function to insert nodes at the end of the list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = NULL;

    // Insert sorted elements (with duplicates)
    insert(head, 1);
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 3);
    insert(head, 4);
    insert(head, 4);
    insert(head, 5);

    cout << "Original List: ";
    printList(head);

    // Remove duplicates
    head = RemoveDuplicatesFromSorted(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
