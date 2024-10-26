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
int maxsumpathutils(Node* root, int &ans){
	if(root==NULL){
		return 0;
	}
	int left = maxsumpathutils(root->left,ans);
	int right = maxsumpathutils(root->right,ans);
	int maxsum = max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans = max(ans,maxsum);
    int singlepathsum= max(root->data,max(root->data+left,root->data+right));
    return singlepathsum;
}
int maxsumpath(Node*root){
	int ans = INT_MIN;
	maxsumpathutils(root,ans);
	return ans;
}
int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	cout<<maxsumpath(root);
	
}