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

 void flattentree(Node* root){
 	if (root == NULL) {
        return;
    }
 	if(root->left!=NULL){
 		flattentree(root->left);
 		Node* temp = root->right;
 		root->right = root->left;
 		root->left = NULL;
 		Node* t = root->right;
 		while(t->right!=NULL){
 			t= t->right;
		 }
		 t->right = temp;
		 
	 }
	 flattentree(root->right);
 }
 void printFlattenedTree(Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}
int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left= new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	flattentree(root);
	cout<<"Flatten Tree: ";
	printFlattenedTree(root);
	
	
}