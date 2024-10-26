#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data = val;
		left =NULL;
		right = NULL;
		
	}
};
int count(Node* root){
	if(root==NULL){
		return 0;
	}
	return count(root->left) + count(root->right) +1;
	
}
int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(2);
	root->left->left= new Node(2);
	root->left->right = new Node(2);
	root->right->left = new Node(2);
	root->right->right = new Node(2);
	cout<<count(root);
}