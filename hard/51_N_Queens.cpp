#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string> > res;
    vector<int> col, diag, rev_diag;
    int n;
    
    void dfs(vector<string>& sol, int r) {
        if (r == n) {
            res.push_back(sol);
            return;
        }
        
        for (int c = 0; c < n; c++) {
            if (col[c]) continue;
            
            int d = n + c - r, r_d = c + r;
            if (diag[d]) continue;
            if (rev_diag[r_d]) continue;
            
            // before entrance
            col[c] = diag[d] = rev_diag[r_d] = 1;
            sol[r][c] = 'Q';
            
            // depth-first search the solution-tree
            dfs(sol, r + 1);
            
            // after exit
            col[c] = diag[d] = rev_diag[r_d] = 0;
            sol[r][c] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        res = vector<vector<string> >();
        if (!n) return res;
        this->n = n;
        
        // initialization...
        int len = 2 * n + 1;
        col = vector<int>(len, 0);
        diag = vector<int>(len, 0);
        rev_diag = vector<int>(len, 0);
        
        auto sol = vector<string>();
        for (int r = 0; r < n; r++) {
            string s(n, '.');
            sol.push_back(s);
        }
            
        dfs(sol, 0);
        return res;
    }
};