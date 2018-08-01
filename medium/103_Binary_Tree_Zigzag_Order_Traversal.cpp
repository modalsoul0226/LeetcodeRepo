
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


static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        auto res = vector<vector<int> >();
        if (!root) return res;
        
        auto levels = queue<int>();
        auto nodes = queue<TreeNode *>();
        
        nodes.push(root); levels.push(0);
        while (!nodes.empty()) {
            TreeNode *node = nodes.front(); nodes.pop();
            int level = levels.front(); levels.pop();
            
            if (res.size() == level) res.push_back(vector<int>());
            res[level].push_back(node->val);
            
            if (node->left) { nodes.push(node->left); levels.push(level + 1); }
            if (node->right) { nodes.push(node->right); levels.push(level + 1); }
        }
        
        for (int i = 1; i < res.size(); i += 2) reverse(res[i].begin(), res[i].end());
        return res;
    }
};