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
    int sum;
    
    void dfs(TreeNode *root, int acc) {
        if (!root) return;
        acc = acc * 10 + root->val;
        
        auto left = root->left, right = root->right;
        if (!left && !right) sum += acc;
        
        if (left) dfs(root->left, acc);
        if (right) dfs(root->right, acc);
    }
    
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        
        return sum;
    }
};