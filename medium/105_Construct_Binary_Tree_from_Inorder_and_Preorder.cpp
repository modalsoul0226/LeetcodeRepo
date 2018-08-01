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
    TreeNode *build(vector<int> p_order, vector<int> i_order, int p_start, int i_start, int size) {
        auto root = new TreeNode(p_order[p_start]);
        
        int i;
        for (i = 0; i < size; i++)
            if (i_order[i_start + i] == p_order[p_start]) break;
        
        if (i > 0)
            root->left = build(p_order, i_order, p_start + 1, i_start, i);
        if (size - i - 1 > 0)
            root->right = build(p_order, i_order, p_start + i + 1, i_start + i + 1, size - i - 1);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if (!size) return nullptr;
        
      
        return build(preorder, inorder, 0, 0, size);
    }
};