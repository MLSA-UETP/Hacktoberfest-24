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
int main() {
	struct Node* root = new Node(2);
	root->left  = new Node(4);
	root->right = new Node(6);
	root->left->left = new Node(8);
	root->left->right = new Node(10);
	
	cout << "Root: " << root->data << endl;
    cout << "Left Child of Root: " << root->left->data << endl;
    cout << "Right Child of Root: " << root->right->data << endl;
    cout << "Left Child of Left Child: " << root->left->left->data << endl;
    cout << "Right Child of Left Child: " << root->left->right->data << endl;
}