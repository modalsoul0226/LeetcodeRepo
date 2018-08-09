#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int n, k;
    vector<vector<int> > res;
    vector<int> nums;
    
    void dfs(vector<int>& A, int begin, int end, int cur) {
        if (A.size() == k) {
            res.push_back(A);
            return;
        }
        

        for (int i = begin; i <= end; i++) {
            if (i && nums[i - 1] == nums[i] && i > begin)
                continue;
            
            A.push_back(nums[i]);
            
            dfs(A, i + 1, end + 1, cur + 1);
            A.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res = vector<vector<int> >(); res.push_back(vector<int>());
        n = nums.size(); if (!n) return res;
        
        sort(nums.begin(), nums.end());
        this->nums = nums;
        
        for (int i = 1; i <= n; i++) {
            k = i; auto A = vector<int>();
            dfs(A, 0, n - k, 0);
        }
        
        return res;
    }
};