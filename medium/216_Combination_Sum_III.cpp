#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int len, target;
    vector<vector<int> > res;
    
    void dfs(vector<int>& A, int cur, int sum) {
        if (cur == len) {
            if (sum == target)
                res.push_back(A);
            
            return;
        }
        
        int i = 1;
        if (cur) i = A[cur - 1] + 1;
        for (i; i <= 9; i++) {
            if (i + sum > target) break;
            
            A.push_back(i); sum += i;
            dfs(A, cur + 1, sum);
            A.pop_back(); sum -= i;
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        len = k; target = n;
        vector<int> A;
        
        dfs(A, 0, 0);
        return res;
    }
};