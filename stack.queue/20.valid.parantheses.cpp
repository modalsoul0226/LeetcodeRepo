class Solution {
public:
    stack<char> bStack;
    set<char> open = {'[', '(', '{'};
    set<char> close = {']', ')', '}'};
    map<char, char> brackets = {{']', '['}, {'}', '{'}, {')', '('}};

    bool isValid(string s) {
        // clear
        this->bStack = stack<char>();
        // check
        for (char b: s) {
            // open
            if (this->open.find(b) != this->open.end())
                this->bStack.push(b);
            // close
            else if (this->close.find(b) != this->close.end()) {
                if (this->bStack.empty() || this->bStack.top() != this->brackets[b])
                    return false;
                this->bStack.pop();
            }   
        }
        
        return this->bStack.empty();
    }
};