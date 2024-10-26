#include <iostream>
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

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void RecoverBSTutils(Node* root,Node** first,Node** last,Node** mid,Node**prev){
	if(root==NULL){
		return;
	}
	RecoverBSTutils(root->left,first,last,mid,prev);
	if(*prev && root->data<(*prev)->data){
		if(!*first){
			*first = *prev;
			*mid = root;
		}
		else{
			*last = root;
		}
	}
	*prev = root;
	RecoverBSTutils(root->right,first,last,mid,prev);
	
}


void RecoverBST(Node* root){
	Node *first,*last,*mid,*prev;
	first = NULL;
	last = NULL;
	mid = NULL;
	prev = NULL;
	
	RecoverBSTutils(root,&first,&last,&mid,&prev);
	
	if(first && last){
		swap(&(first->data),&(last->data));
	}
	else if(first && mid){
		swap(&(first->data),&(mid->data));
		
	}
	
}

void inorder(Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){
   Node* root = new Node(6);
   root->left = new Node(9);
   root->right = new Node(3);
   root->left->left = new Node(1);
   root->left->right = new Node(4);
   root->right->right = new Node(13);
   
   inorder(root);
   cout<<endl;
   RecoverBST(root);
   inorder(root);
   	
}