#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr) {
    for (int i = start; i <= end; i++) {  // <= instead of <
        if (inorder[i] == curr) {
            return i;
        }
    }
    return -1;
}

node* buildtree(int preorder[], int inorder[], int start, int end) {
    static int idx = 4;
    if (start > end) {
        return NULL;
    }
    int curr = preorder[idx];
    idx--;
    node* newNode = new node(curr);  // Avoid shadowing the `node` identifier
    if (start == end) {
        return newNode;  // Return the node itself instead of NULL
    }
    int pos = search(inorder, start, end, curr);
    newNode->left = buildtree(preorder, inorder, start, pos - 1);
    newNode->right = buildtree(preorder, inorder, pos + 1, end);
    return newNode;
}

void inordertree(node* root) {
    if (root == NULL) {  // Base case for recursion
        return;
    }
    inordertree(root->left);
    cout << root->data << " ";
    inordertree(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    node* root = buildtree(preorder, inorder, 0, 4);
    inordertree(root);
    return 0;
}
