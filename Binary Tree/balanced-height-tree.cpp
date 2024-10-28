#include <iostream>
#include <cmath>  // For abs() function
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Height function with base case to stop recursion
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

// Optimized balanced tree check
bool balancedtree(Node* root) {
    if (root == NULL) {
        return true;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1) {
        return false;
    }

    return balancedtree(root->left) && balancedtree(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if (balancedtree(root)) {
        cout << "Balanced Tree" << endl;
    } else {
        cout << "Unbalanced Tree" << endl;
    }

    return 0;
}
