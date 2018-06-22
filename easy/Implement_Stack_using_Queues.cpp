#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> stack;

public:
    /** Initialize your data structure here. */
    MyStack() {
        this->stack = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        this->stack.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tmp = queue<int>();
        while (this->stack.size() != 1) {
            tmp.push(this->stack.front());
            this->stack.pop();
        }
        
        int res = this->stack.front();
        this->stack = tmp;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        queue<int> tmp = queue<int>();
        int item;
        
        do {
            tmp.push((item = this->stack.front()));
            this->stack.pop();
        } while (!this->stack.empty());
        
        this->stack = tmp;
        return item;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return this->stack.empty();   
    }
};

int main() {
    MyStack obj = MyStack();
    obj.push(5); obj.push(6);
    int param_2 = obj.pop(); cout << param_2 << endl;
    int param_3 = obj.top(); cout << param_3 << endl;
    bool param_4 = obj.empty(); cout << param_4 << endl;
}