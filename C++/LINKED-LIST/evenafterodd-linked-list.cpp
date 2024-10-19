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
	head = n;
}
void insertATtail(node* &head,int val){
	if(head==NULL){
		insertAThead(head,val);
		return;
	}
	node* n = new node(val);
	
	node* temp  = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = n;
}
void avenafterodd(node* &head){
	node* odd = head;
	node* even = head->next;
	node* evenstart = even;
	while(odd->next!=NULL && even->next!=NULL){
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
		
	}
	odd->next = evenstart;
	if(odd->next!=NULL){
		even->next = NULL;
	}
}
void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
		
	}
	cout<<"NULL";
}
int main(){
	node* head = NULL;
	insertATtail(head,1);
	insertATtail(head,2);
	insertATtail(head,3);
	insertATtail(head,4);
	display(head);
	cout<<endl;
	avenafterodd(head);
	display(head);
}