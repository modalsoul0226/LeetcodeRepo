#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        auto dp = triangle.back();
        
        for (int k = n - 2; k >= 0; k--)
            for (int i = 0; i <= k; i++)
                dp[i] = min(dp[i], dp[i + 1]) + triangle[k][i];
        
        return dp[0];
    }
};