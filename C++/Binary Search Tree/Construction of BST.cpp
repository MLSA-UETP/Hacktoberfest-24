#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* constructTree(int preorder[], int* preorderIdx, int key, int min, int max, int n) {
    if (*preorderIdx >= n) {
        return NULL;
    }

    Node* root = NULL;

    if (key > min && key < max) {
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n) {
            root->left = constructTree(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }

        if (*preorderIdx < n) {
            root->right = constructTree(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }

    return root;
}

void printPreorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int preorderArr[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;

    Node* root = constructTree(preorderArr, &preorderIdx, preorderArr[0], INT_MIN, INT_MAX, n);

    cout << "Preorder traversal of constructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
