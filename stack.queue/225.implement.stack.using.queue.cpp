class MyStack {
public:
    queue<int> s;
    
    /** Initialize your data structure here. */
    MyStack() {
       // pass 
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tmp;
        tmp.push(x);

        // push to the front
        while (!this->s.empty()) {
            tmp.push(this->s.front());
            this->s.pop();
        }
        
        this->s = tmp;
    }
    
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // pop
        int res = this->s.front();
        this->s.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        // top
        return this->s.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return this->s.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */