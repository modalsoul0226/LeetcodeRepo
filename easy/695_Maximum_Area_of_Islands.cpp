#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    vector<vector<int> > G;
    int r, c;
    
    int dfs(int x, int y) {
        if (x < 0 || x >= r || y < 0 || y >= c) return 0;
        if (G[x][y] == 0) return 0;
        
        G[x][y] = 0; int acc = 1;
        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++)
                if (dy * dx == 0 && dx != dy)
                    acc += dfs(x + dx, y + dy);
    
        return acc;
    }
    
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        G = grid; int acc = 0;
        
        r = grid.size(); if (!r) return acc;
        c = grid[0].size(); if (!c) return acc;
        
        for (int x = 0; x < r; x++)
            for (int y = 0; y < c; y++)
                if (G[x][y] == 1)
                    { int count = dfs(x, y); acc = max(count, acc); }
        
        return acc;
    }
};