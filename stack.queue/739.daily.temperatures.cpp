class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        // result diffs
        vector<int> res(len, 0);
        // a stack of indices of previous ts
        stack<int> prevs;

        // iterate each t which is a potential higher figure than a previous t
        for (int i = 0; i < len; i++) {
            // if a previous t is smaller than the current t 
            while (!prevs.empty() && T[i] > T[prevs.top()]) {
                res[prevs.top()] = i - prevs.top();
                prevs.pop();
            }

            // push current t as prevs
            prevs.push(i);
        }
        
        return res;
    }
};