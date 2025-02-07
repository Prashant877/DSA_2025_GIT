//
//  main.cpp
//  BoundryTraversal
//
//  Created by Prashant on 06/02/25.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Print the left boundary (excluding leaf nodes)
void printLeftBoundary(Node* root) {
    Node* curr = root->left;
    while (curr) {
        if (!(curr->left == nullptr && curr->right == nullptr)) {
            cout << curr->data << " ";
        }
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

// Print all leaf nodes (left to right)
void printLeafNodes(Node* root) {
    if (!root) return;
    
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
        return;
    }
    
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// Print the right boundary (excluding leaf nodes) in reverse order
void printRightBoundary(Node* root) {
    stack<int> s;
    Node* curr = root->right;
    
    while (curr) {
        if (!(curr->left == nullptr && curr->right == nullptr)) {
            s.push(curr->data);  // Store nodes in stack
        }
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    
    // Print stored nodes
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

// Boundary Traversal Function
void boundaryTraversal(Node* root) {
    if (!root) return;

    cout << root->data << " ";  // Print root node

    // Print left boundary (excluding root & leaf nodes)
    printLeftBoundary(root);

    // Print all leaf nodes
    printLeafNodes(root);

    // Print right boundary (excluding root & leaf nodes)
    printRightBoundary(root);
}

int main() {
    // Example Binary Tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6
    //        / \   \
    //       7   8   9
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right->right = new Node(9);

    cout << "Boundary Traversal: ";
    boundaryTraversal(root);
    cout << endl;

    return 0;
}
