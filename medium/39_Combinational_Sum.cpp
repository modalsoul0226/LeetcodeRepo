#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    vector<vector<int> > res;
    vector<int> nums;
    int target;
    
    void dfs(vector<int>& A, const int size, int sum) {
        if (A.size() == size) {
            if (sum == target) res.push_back(A);
            return;
        }
        
        for (auto& num: nums) {
            int last = A.size() - 1;
            if (last >= 0 && A[last] > num) continue;
            if (sum + num > target) continue;
            
            A.push_back(num); sum += num;
            dfs(A, size, sum);
            A.pop_back(); sum -= num;
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->nums = candidates;
        this->target = target;
        
        res = vector<vector<int> >();
        if (!nums.size()) return res;
        
        int len = target / nums[0];
        if (!len) return res;
        
        for (int i = 1; i <= len; i++) {
            auto A = vector<int>();
            dfs(A, i, 0);
        }
        
        return res;
    }
};