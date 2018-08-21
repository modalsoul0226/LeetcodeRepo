#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > res;
    int k, n;
    
    void dfs(vector<int>& A, int begin, int end) {
        if (A.size() == k) {
            res.push_back(A);
            return;
        }
        
        for (int i = begin; i <= end; i++) {
            A.push_back(i);
            dfs(A, i + 1, end + 1);
            A.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        this->k = k; this->n = n; 
        res = vector<vector<int> >();
        
        auto A = vector<int>();
        dfs(A, 1, n - k + 1);
        
        return res;
    }
};