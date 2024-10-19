#include <iostream>
#define n 20
using namespace std;
class queue{
	int* arr;
	int front;
	int back;
	public:
		queue(){
			arr = new int[n];
			front = -1;
			back = -1;			
		}
	void Enqueue(int x){
		if(back == n-1){
			cout<<"Queue Overflow"<<endl;
			return;
		}
		back++;
		arr[back]= x;
		
		if(front == -1){
			front++;
		}
	}
	void Dequeue(){
		if(front==-1 || front>back){
			cout<<"No Element in queue"<<endl;
			return;
		}
		front++;
	}
	int peek(){
		if(front==-1 || front>back){
			cout<<"No Element in queue"<<endl;
			return -1;
		}
		return arr[front];
	}
	bool empty(){
		if(front==-1 || front>back){
			return true;
		}
		return false;
	}
};
int main(){
	queue q;
	q.Enqueue(6);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	cout<<q.peek()<<endl;
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	cout<<q.empty();
}