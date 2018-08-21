#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int n;
    map<int,int> c1, c2;
    vector<int> nums;
    vector<vector<int> > res;
    
    void dfs(vector<int> A) {
        if (A.size() == n) {
            res.push_back(A);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            
            if (i && nums[i - 1] == num) continue;
            if (c2.count(num) && c1[num] <= c2[num]) continue;
            
            // before entrance
            if (c2.count(num)) c2[num]++; else c2[num] = 1;
            A.push_back(num);
            
            dfs(A);
            
            // after exit
            c2[num]--; A.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        this->nums = nums;
        
        for (auto& num: nums) {
            if (c1.count(num)) c1[num]++;
            else c1[num] = 1;
        }
        
        auto A = vector<int>();
        dfs(A);
        
        return res;
    }
};