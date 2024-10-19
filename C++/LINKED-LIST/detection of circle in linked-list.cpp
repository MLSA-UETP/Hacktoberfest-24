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
void insertATnode(node* &head,int val){
	node* n = new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
		
	}
	temp->next=n;
}
void insertAThead(node* &head,int val){
	node* n= new node(val);
	n->next = head;
	head=n; 
}
void makecycle(node* &head,int pos){
	node* temp = head;
	node* startnode;
	int count = 1;
	while(temp->next!=NULL){
		if(count==pos){
			startnode = temp;
			
		}
		temp = temp->next;
		count++;
	}
	temp->next = startnode;
}
bool detectcycle(node* &head){
	node* slow=head;
	node* fast=head;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(fast==slow){
			return true;
		}
	}
	return false;
}
void removecycle(node* &head){
	node* slow = head;
	node* fast = head;
	do{
		slow = slow->next;
		fast = fast->next->next;
	}	while(slow!=fast);
		fast = head;
	
	while(fast->next!=slow->next){
		fast= fast->next;
		slow = slow->next;
		
	}
	slow->next = NULL;
	}

void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp= temp->next;
	}
	cout<<"NULL";
}

int main(){
	node* head=NULL;
	insertATnode(head,2);
	insertATnode(head,4);
	insertATnode(head,6);
	insertAThead(head,1);
	makecycle(head,3);
	//display(head);
	cout<<detectcycle(head)<<endl;
	removecycle(head);
	cout<<detectcycle(head);
	//display(head);
}