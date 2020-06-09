class MyQueue {
public:
    stack<int> s; // stack
    stack<int> q; // queue
    
    /** Initialize your data structure here. */
    MyQueue() {
        // pass
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        this->s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // if queue is empty, pull more elements from the stack
        if (this->q.empty()) {
            while (!this->s.empty()) {
                this->q.push(this->s.top());
                this->s.pop();
            }
        }
        
        // pop
        int res = this->q.top();
        this->q.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        // if queue is empty, pull more elements from the stack
        if (this->q.empty()) {
            while (!this->s.empty()) {
                this->q.push(this->s.top());
                this->s.pop();
            }
        }
        
        // peek
        return this->q.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return this->q.empty() && this->s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */