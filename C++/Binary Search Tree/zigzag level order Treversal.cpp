#include <iostream>
#include <stack>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void zigzag(Node* root){
	if(root==NULL){
		return;
	}
	stack<Node*> currlevel;
	stack<Node*> nextlevel;
	
	bool leftTOright = true;
	currlevel.push(root);
	
	while(!currlevel.empty()){
		Node* temp = currlevel.top();
		currlevel.pop();
		
		if(temp){
			cout<<temp->data<<" ";
		
		if(leftTOright){
			if(temp->left){
			
			nextlevel.push(temp->left);
		    }
		    if(temp->right){
		    	nextlevel.push(temp->right);
			}
			}
		else{
				if(temp->right){
			    	nextlevel.push(temp->right);
				}
				if(temp->left){
			    	nextlevel.push(temp->left);
				}
		    }
		}
		if(currlevel.empty()){
			leftTOright = !leftTOright;
			swap(currlevel,nextlevel);
		}
	}
	
}
int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(12);
	root->left->left = new Node(7);
	root->left->right = new Node(9);
    zigzag(root);
	cout<<endl;	
	
}