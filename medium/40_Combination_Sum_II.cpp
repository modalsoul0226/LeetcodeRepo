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
    map<int,int> c1, c2;
    int target;
    
    void dfs(vector<int>& A, const int size, int sum) {
        if (A.size() == size) {
            if (sum == target) res.push_back(A);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int last = A.size() - 1;
            
            if (i && nums[i - 1] == nums[i]) continue;
            if (c2.count(num) && c2[num] >= c1[num]) continue;
            if (last >= 0 && A[last] > num) continue;
            if (sum + num > target) continue;
            
            if (c2.count(num)) c2[num]++; else c2[num] = 1;
            A.push_back(num); sum += num;
            
            dfs(A, size, sum);
            c2[num]--; A.pop_back(); sum -= num;
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        nums = candidates; this->target = target;
        c1 = map<int,int>();
        
        for (int num: nums) {
            if (c1.count(num)) c1[num]++;
            else c1[num] = 1;
        }
        
        res = vector<vector<int> >();
        if (!nums.size()) return res;
        
        int len = target / nums[0];
        if (!len) return res;
        
        for (int i = 1; i <= len; i++) {
            auto A = vector<int>();
            c2 = map<int,int>();
            
            dfs(A, i, 0);
        }
        
        return res;
    }
};