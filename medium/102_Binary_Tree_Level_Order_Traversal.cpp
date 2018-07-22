#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        auto res = vector<vector<int> >();
        if (!root) return res;
        
        auto visited = queue<TreeNode *>();
        auto levels = queue<int>();
        
        visited.push(root);
        levels.push(0);
        
        while (!visited.empty()) {
            TreeNode *node = visited.front(); visited.pop();
            int level = levels.front(); levels.pop();
            
            if (res.size() <= level) res.push_back(vector<int>());
            res[level].push_back(node->val);
            
            if (node->left) { visited.push(node->left); levels.push(level + 1); }
            if (node->right) { visited.push(node->right); levels.push(level + 1); }
        }
        
        return res;
    }
};