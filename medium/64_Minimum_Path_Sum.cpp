#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); if (!m) return 0;
        int n = grid[0].size(); if (!n) return 0;
        int dp[m][n]; memset(dp, 0, sizeof(dp));
        
        dp[0][0] = grid[0][0];
        for (int r = 1; r < m; r++) dp[r][0] = dp[r - 1][0] + grid[r][0];
        for (int c = 1; c < n; c++) dp[0][c] = dp[0][c - 1] + grid[0][c];
        
        for (int r = 1; r < m; r++)
            for (int c = 1; c < n; c++)
                dp[r][c] = min(dp[r - 1][c], dp[r][c - 1]) + grid[r][c];
        
        return dp[m - 1][n - 1];
    }
    
//  BackTracking solution -- TLE
//     int min, m, n;
//     vector<vector<int> > grid;
    
//     void dfs(int r, int c, int sum) {
//         if (sum >= min || r >= m || c >= n)
//             return;
//         if (r == m - 1 && c == n - 1)
//             { min = sum; return; }
        
//         if (r < m - 1 && grid[r + 1][c] + sum < min)
//             dfs(r + 1, c, grid[r + 1][c] + sum);
//         if (c < n - 1 && grid[r][c + 1] + sum < min)
//             dfs(r, c + 1, grid[r][c + 1] + sum);
//     }
    
//     int minPathSum(vector<vector<int>>& grid) {
//         min = 0x7fffffff; this->grid = grid;
        
//         m = grid.size(); if (!m) return 0;
//         n = grid[0].size(); if (!n) return 0;

//         dfs(0, 0, grid[0][0]);
    
//         return min;
//     }
};