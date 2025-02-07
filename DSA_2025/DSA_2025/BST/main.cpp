//
//  main.cpp
//  BST
//
//  Created by Prashant on 07/02/25.
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

// Function to insert a node in BST
Node* insertBST(Node* root, int key) {
    // If the tree is empty, return a new node
    if (root == nullptr) {
        return new Node(key);
    }

    // Recursively insert into the correct subtree
    if (key < root->data) {
        root->left = insertBST(root->left, key);
    } else if (key > root->data) {
        root->right = insertBST(root->right, key);
    }

    return root; // Return the unchanged root node
}

bool searchInBST(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == key) {
        return true;
    } else if (key < root->data) {
        return searchInBST(root->left, key);
    } else {
        return searchInBST(root->right, key);
    }
}

// Function to find the minimum value node in a BST (used for deletion)
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
Node* deleteFromBST(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteFromBST(root->left, key);
    } else if (key > root->data) {
        root->right = deleteFromBST(root->right, key);
    } else {
        // Node found: 3 cases

        // Case 1: No child (Leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);  // Find inorder successor
        root->data = temp->data;  // Copy inorder successor value to root
        root->right = deleteFromBST(root->right, temp->data);  // Delete inorder successor
    }

    return root;
}

// Inorder Traversal (to verify BST structure)
void inorderTraversal(Node* root) {
    if (!root) return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    
    // Insert nodes into the BST
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 70);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 60);
    insertBST(root, 80);
    
    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;
    
    /*int key = 40;
        if (searchInBST(root, key)) {
            cout << key << " found in BST." << endl;
        } else {
            cout << key << " not found in BST." << endl;
        }

        key = 25;
        if (searchInBST(root, key)) {
            cout << key << " found in BST." << endl;
        } else {
            cout << key << " not found in BST." << endl;
        }*/

    cout << "Inorder before deletion: ";
        inorderTraversal(root);
        cout << endl;

        // Delete a node from BST
        int key = 50;
        root = deleteFromBST(root, key);
        cout << "Inorder after deleting " << key << ": ";
        inorderTraversal(root);
        cout << endl;
    return 0;
}
