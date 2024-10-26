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
	return max(treeheight(root->left),treeheight(root->right)) +1;
	
}

int calDaimeter(Node* root){        // O(n^2) not optimize Approach
	if(root==NULL){
		return 0;
	}
	int leftheiight= treeheight(root->left);
	int Rightheight = treeheight(root->right);
	int height = leftheiight + Rightheight + 1;
	int leftdaimeter = calDaimeter(root->left);
	int rightdaimeter = calDaimeter(root->right);
	return max(height,max(leftdaimeter,rightdaimeter));
}
int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout<<calDaimeter(root);	
}