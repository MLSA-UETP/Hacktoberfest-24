#include <iostream>
#include <stack>
using namespace std;
class queue{
	stack<int> s1;
	stack<int> s2;
	public:
		void Enqueue(int x){
			s1.push(x);
		}
		int Dequeue(){
			if(s1.empty() && s2.empty()){
				cout<<"Error"<<endl;
			}
			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
			int topval = s2.top();
			s2.pop();
			return topval;
		}
		bool empty(){
			if(s1.empty() && s2.empty()){
				return true;
			}
			return false;
		}
};
int main(){
	queue q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	cout<<q.Dequeue()<<endl;

	cout<<q.empty()<<endl;
	cout<<q.Dequeue()<<endl;
}