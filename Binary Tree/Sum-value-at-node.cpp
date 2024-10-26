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
int countvalATnode(Node* root){
	if(root ==NULL){
		return 0;
	}
	return countvalATnode(root->left) + countvalATnode(root->right)+ root->data;
}
int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(2);
	root->left->left= new Node(2);
	root->left->right = new Node(2);
	root->right->left = new Node(2);
	root->right->right = new Node(2);
	cout<<countvalATnode(root);
	
}