#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

int treeheight(Node* root){
	if(root==NULL){
		return 0;
	}
	int leftheight = treeheight(root->left);
	int rightheight = treeheight(root->right);
	return max(leftheight,rightheight)+1;
	
}
int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout<<treeheight(root);
	
}