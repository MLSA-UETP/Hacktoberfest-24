#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

int length(node* head){
	int l = 0;
	node* temp = head;
	while(temp != NULL){
		l++;
		temp = temp->next;
	}
	return l;
	
}
node* kappend(node* &head,int k){
	node* newhead;
	node* newtail;
	node* tail = head;
	int l = length(head);
	int count = 1;
	while(tail->next!=NULL){
		if(count==l-k){
			newtail = tail;
		}
		if(count==l-k+1){
			newhead = tail;
		}
		tail = tail->next;
		count++;
	}
	newtail->next=NULL;
	tail->next = head;
	return newhead;
	
}

void insertTOhead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertTOtail(node* &head, int val) {
    if (head == NULL) {
        insertTOhead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main() {
    node* head = NULL;
    insertTOtail(head, 1);
    insertTOtail(head, 2);
    insertTOtail(head, 3);
    insertTOtail(head, 4);
    insertTOtail(head,9);
    display(head);
    node* newhead = kappend(head,3);
    display(newhead);
}
