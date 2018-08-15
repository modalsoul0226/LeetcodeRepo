static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > res;
    int target;
    
    void dfs(TreeNode* root, int sum, vector<int>& path) {
        if (!root) return;
        
        sum += root->val; path.push_back(root->val);
        
        auto left = root->left, right = root->right;
        if (!left && !right) {
            if (sum == target)
                res.push_back(path);
            path.pop_back();
            return;
        }
        
        dfs(left, sum, path);
        dfs(right, sum, path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path; target = sum;
        dfs(root, 0, path);
        
        return res;
    }
};