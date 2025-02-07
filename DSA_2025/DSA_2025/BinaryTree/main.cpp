//
//  main.cpp
//  BinaryTree
//
//  Created by Prashant on 05/02/25.
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

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void printLevelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

int sumAtKthLevel(Node* root, int k) {
    if (root == NULL) return 0;

    queue<Node*> q;
    q.push(root);
    int level = 0;
    int sum = 0;

    while (!q.empty()) {
        int size = q.size(); // Number of nodes at current level

        if (level == k) {
            // If we reach the kth level, sum all node values
            while (size--) {
                Node* temp = q.front();
                q.pop();
                sum += temp->data;
            }
            return sum; // Return sum immediately after processing k-th level
        }

        // Process current level and enqueue next level nodes
        while (size--) {
            Node* temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        level++;
    }

    return 0; // If k is out of range
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "PreOrder Traversal:" << endl;
    preOrder(root);
    cout << endl;

    cout << "InOrder Traversal:" << endl;
    inOrder(root);
    cout << endl;

    cout << "PostOrder Traversal:" << endl;
    postOrder(root);
    cout << endl;

    cout << "Level Order Traversal:" << endl;
    printLevelOrder(root);
    cout << endl;
    
    int k = 2;
    cout << "Sum at level " << k << ": " << sumAtKthLevel(root, k) << endl;

    return 0;
}
