#include <iostream>
#include <vector>
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

vector<Node*> constructTrees(int start, int end) {
    vector<Node*> trees;
    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++) {  // Corrected loop condition
        vector<Node*> leftsubtree = constructTrees(start, i - 1);
        vector<Node*> rightsubtree = constructTrees(i + 1, end);

        for (int j = 0; j < leftsubtree.size(); j++) {
            Node* left = leftsubtree[j];  // Corrected vector access

            for (int k = 0; k < rightsubtree.size(); k++) {  // Corrected loop
                Node* right = rightsubtree[k];
                Node* root = new Node(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }

    return trees;
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<Node*> totaltrees = constructTrees(1, 3);
    for (int i = 0; i < totaltrees.size(); i++) {
        cout << "Tree " << (i + 1) << " : ";
        preorder(totaltrees[i]);
        cout << endl;
    }

    return 0;
}
