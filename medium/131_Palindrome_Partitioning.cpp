#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();


class Solution {
public:
    string s;
    vector<vector<string> > res;
    
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++; j--;
        }
        
        return true;
    }
    
    
    void dfs(vector<string>& A, int idx) {
        if (idx == s.size()) {
            res.push_back(A);
            return;
        }
        
        for (int len = 1; len <= s.size() - idx; len++)
            if ((isPalindrome(s, idx, idx + len - 1))) {
                A.push_back(s.substr(idx, len));
                dfs(A, idx + len);
                A.pop_back();
            }

    }
    
    
    vector<vector<string>> partition(string s) {
        this->s = s;
        
        auto A = vector<string>();
        dfs(A, 0);
        
        return res;
    }
};
