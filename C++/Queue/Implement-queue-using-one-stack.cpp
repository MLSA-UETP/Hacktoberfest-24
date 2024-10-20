#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1;

public:
    
    void Enqueue(int x) {
        s1.push(x);
    }

   
    int Dequeue() {
        if (s1.empty()) {
            cout << "Queue underflow" << endl;
            return -1;  
        }

        int x = s1.top();
        s1.pop();

       
        if (s1.empty()) {
            return x;
        }

        
        int temp = Dequeue();
        s1.push(x);

        return temp;
    }

  
    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);

    cout << "Dequeue: " << q.Dequeue() << endl; 

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; 

    return 0;
}
