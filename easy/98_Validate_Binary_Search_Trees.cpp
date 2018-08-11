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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        auto nodes = stack<TreeNode *>();
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        
        while (!nodes.empty() || curr) {
            if (curr) {
                nodes.push(curr);
                curr = curr->left;
            
            } else {
                curr = nodes.top(); nodes.pop();
                if (prev && prev->val >= curr->val) return false;
                
                prev = curr;
                curr = curr->right;
            }
        }
        
        return true;
    }
};