//
//  main.cpp
//  countNodes
//
//  Created by Prashant on 06/02/25.
//

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int countNodes(Node* root) {
    if (root == nullptr){
        return 0;
    }
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumOfAllNodes(Node* root) {
    if (root == nullptr){
        return 0;
    }
    
    return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
}

void rightView(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        int lastNode = -1;

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            lastNode = node->data;  // Store last node at each level

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << lastNode << " ";  // Print last node at this level
    }
}

void leftView(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        bool firstNode = true;

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            
            if (firstNode) {
                cout << node->data << " "; // Print first node at this level
                firstNode = false;
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout << "Total number of nodes: " << countNodes(root) << endl;
    cout << "Sum of all nodes: " << sumOfAllNodes(root) << endl;
    cout << "Right View: ";
        rightView(root);
        cout << endl;
    cout << "Left View: ";
        leftView(root);
        cout << endl;
    
    return 0;
}

