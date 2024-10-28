#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to find the Lowest Common Ancestor (LCA) of two nodes
Node* lca(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    Node* leftlca = lca(root->left, n1, n2);
    Node* rightlca = lca(root->right, n1, n2);

    if (leftlca && rightlca) {
        return root;
    }
    return (leftlca != NULL) ? leftlca : rightlca;
}

// Function to find the distance from root to a given key 'k'
int findDist(Node* root, int k, int dist) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == k) {
        return dist;
    }
    int left = findDist(root->left, k, dist + 1);
    if (left != -1) {  // Corrected condition
        return left;
    }
    return findDist(root->right, k, dist + 1);
}

// Function to find the distance between two nodes in a binary tree
int distBetweenNodes(Node* root, int n1, int n2) {
    Node* lca1 = lca(root, n1, n2);
    int d1 = findDist(lca1, n1, 0);
    int d2 = findDist(lca1, n2, 0);
    return d1 + d2;
}

int main() {
    Node* root = new Node(9);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    cout << "Distance between nodes 4 and 5: " << distBetweenNodes(root, 4, 5) << endl;

    return 0;
}
