#include <iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node(int val){
		data = val;
		next = NULL;
	}
};
void insertAThead(node* &head,int val){
	node* n = new node(val);
	n->next = head;
	head=n;
}
void insertATtail(node* &head,int val){
	node* n= new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
		
	}
	temp->next = n;
}
bool search(node* head,int key){
	node* temp = head;
	while(temp!=NULL){
		if(temp->data == key){
			return true;
		}
		temp = temp->next;
	}
	
return false;
}
void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
void deleteAThead(node* &head){
	node* todelete = head;
	head = head->next;
	delete todelete;
}
void deletenode(node* &head,int val){
	if(head==NULL){
		return;
	}
	if(head->next==NULL){
		deleteAThead(head);
		return;
	}
	node* temp = head;
	while(temp->next->data!=val){
	temp = temp->next;		
	}
	node* todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}

int main(){
	node* head= NULL;
	insertATtail(head,1);
	insertATtail(head,2);
	insertATtail(head,3);
	insertATtail(head,4);
	insertATtail(head,5);
	insertATtail(head,6);
	insertAThead(head,9);
	cout<<search(head,87)<<endl;
	display(head);
	deletenode(head,5);
	deleteAThead(head);
	display(head);
};