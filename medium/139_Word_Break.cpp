#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if (!wordDict.size())
            return false;
        
        set<string> wordSet;
        for (auto each: wordDict)
            wordSet.insert(each);
        
        int dp[s.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        for (int i = 1; i <= s.size(); i++)
            for(int j = i - 1; j >= 0; j--) {
                if (!dp[j]) continue;
                string seg = s.substr(j, i - j);
                
                if (wordSet.count(seg)) {
                    dp[i] = 1;
                    break;
                }
            }
        
        if (dp[s.size()])
            return true;
        else
            return false;
    }
};
