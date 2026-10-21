#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, value;

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Inorder sequence: ";
    inorder(root);

    return 0;
}