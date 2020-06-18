class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();

        vector<int> res(size, -1);
        stack<int> prevs;

        // first iteration (search for the larger element that comes after)
        for (int i = 0; i < size; i++) {
            while (!prevs.empty() && nums[i] > nums[prevs.top()]) {
                res[prevs.top()] = nums[i];
                prevs.pop();
            }
            
            prevs.push(i);
        }

        // second iteration (search for the larger element that comes before)
        for (int i = 0; i < size; i++) {
            while (!prevs.empty() && nums[i] > nums[prevs.top()]) {
                res[prevs.top()] = nums[i];
                prevs.pop();
            }
        }
        
        return res;
    }
};