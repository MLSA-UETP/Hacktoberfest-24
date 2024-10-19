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
class Queue{
	node* front;
	node* back;
	public:
	Queue(){
		front = NULL;
		back = NULL;
	}
	
	void Enqueue(int x){
		node* n = new node(x);
		
		if(front== NULL){
			front=n;
			back = n; 
		}
		back->next = n;
		back = n;
	}
	void Dequeue(){
		if(front==NULL){
			cout<<"no element to pop"<<endl;
			return;
		}
		node* todelete = front;
		front = front->next;
		delete todelete;
		
	}
	int peek(){
		if(front==NULL){
			return -1;
		}
		return front->data;
	}
	bool empty(){
		if(front==NULL){
			return true;
		}
		return false;
	}
};
int main(){
	Queue q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	cout<<q.peek()<<endl;
	q.Dequeue();
	cout<<q.peek()<<endl;
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	cout<<q.empty()<<endl;
	
	
}