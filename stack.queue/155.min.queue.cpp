#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class MinQueue {
public:
    stack<int> minQueue;
    queue<int> q;

    /** initialize your data structure here. */
    MinQueue() {
       this->minQueue.push(INT_MAX);
    }

    void push(int x) {
        this->q.push(x);

        // transform minQueue to a stack
        stack<int> s;
        while (this->minQueue.size() != 1) {
            s.push(this->minQueue.top());
            this->minQueue.pop();
        }

        // push x
        s.push(x);

        // build min queue from the stack
        while (!s.empty()) {
            int min = this->minQueue.top();
            int val = s.top();
            min = val < min ? val : min;

            this->minQueue.push(min);
            s.pop();
        }
    }
    
    void pop() {
        this->q.pop();
        this->minQueue.pop();
    }
    
    int top() {
        return this->q.front();
    }
    
    int getMin() {
        return this->minQueue.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
    MinQueue *q = new MinQueue();
    q->push(1);
    q->push(2);
    q->push(3);
    cout << q->getMin() << endl;
    q->pop();
    cout << q->top() << endl;
    cout << q->getMin() << endl;
    q->push(0);
    cout << q->getMin() << endl;
    cout << q->top() << endl;
}
