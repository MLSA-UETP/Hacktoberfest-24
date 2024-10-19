
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


node* reverse(node* &head){
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;
	while(currptr!= NULL){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
	}
	return prevptr;
}
node*  recurssive(node* &head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* newhead = recurssive(head->next);
	head->next->next = head;
	head->next = NULL;
	return newhead;
}
node* reverseknode(node* &head,int k){
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;
	int count = 0;
	while(currptr!=NULL && count<k){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
		count++;
	}
	if(nextptr!=NULL){
	head->next=reverseknode(nextptr,k);
}
return prevptr;
}
void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
		
	}
	cout<<"NULL"<<endl;
}
int main(){
	node* head= NULL;
	insertATtail(head,1);
	insertATtail(head,2);
	insertATtail(head,3);
	insertATtail(head,4);
	
	display(head);
	node* newhead = reverse(head);
	//node* newhead = recurssive(head);
	//display(newhead);
	int k =2;
	//node* newhead = reverseknode(head,k);
	display(newhead);
	
};