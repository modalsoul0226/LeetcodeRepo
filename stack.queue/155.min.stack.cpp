class MinStack {
public:
    stack<int> s;
    stack<int> minStack;

    /** initialize your data structure here. */
    MinStack() {
       this->minStack.push(INT_MAX);
    }
    
    void push(int x) {
        int min = this->minStack.top();
        min = x < min ? x : min;
        
        this->minStack.push(min);
        this->s.push(x);
    }
    
    void pop() {
        this->s.pop();
        this->minStack.pop();
    }
    
    int top() {
        return this->s.top();
    }
    
    int getMin() {
        return this->minStack.top();
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