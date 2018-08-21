#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char> > G;
    int r, c;
    
    void dfs(int x, int y) {
        if (x < 0 || x >= r || y < 0 || y >= c) return;
        if (G[x][y] == '0') return;
        
        G[x][y] = '0';
        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++)
                if (dy * dx == 0 && dx != dy)
                    dfs(x + dx, y + dy);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        G = grid; int acc = 0;
        
        r = grid.size(); if (!r) return acc;
        c = grid[0].size(); if (!c) return acc;
        
        for (int x = 0; x < r; x++)
            for (int y = 0; y < c; y++)
                if (G[x][y] == '1')
                    { acc++; dfs(x, y); }
        
        return acc;
    }
};