#include <iostream>
#include <climits>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int val) : data(val), left(NULL), right(NULL) {}
};

struct info {
	int size;
	int min;
	int max;
	int ans;
	bool isBST;
};

info largestBSTinBT(Node* root){
	if(root == NULL){
		return {0, INT_MIN, INT_MAX, 0, true};
	}
	if(root->left == NULL && root->right == NULL){
		return {1, root->data, root->data, 1, true};
	}
	
	info leftBST = largestBSTinBT(root->left);
	info rightBST = largestBSTinBT(root->right);
	
	info curr;
	curr.size = 1;  // Current node itself counts
	if(leftBST.isBST && rightBST.isBST && leftBST.max < root->data && rightBST.min > root->data){
		curr.size += leftBST.size + rightBST.size;
		curr.min = min(leftBST.min, root->data);
		curr.max = max(rightBST.max, root->data);
		curr.ans = curr.size;
		curr.isBST = true;
	}
	else {
		curr.size = 0;
		curr.min = INT_MIN;
		curr.max = INT_MAX;
		curr.ans = max(leftBST.ans, rightBST.ans);
		curr.isBST = false;
	}
	return curr;
}

int main(){
	Node* root = new Node(15);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(5);
	
	cout << largestBSTinBT(root).ans << endl;
	return 0;
}
