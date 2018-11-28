#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int dp[len + 1]; memset(dp, 0, sizeof(dp));

        // init...
        dp[0] = 0; dp[1] = nums[0];

        for (int i = 2; i <= len; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);

        return dp[len];
    }
};


int main() {
    auto sol = Solution();
    int sample[] = {2,7,9,3,1};
    
    vector<int> nums;
    for (int i = 0; i < 5; i++) nums.push_back(sample[i]);
    cout << sol.rob(nums) << endl;
}