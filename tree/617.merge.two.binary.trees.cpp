int speedUp = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!(t1 || t2)) return nullptr;
        
        if (!t1) t1 = new TreeNode(0);
        if (!t2) t2 = new TreeNode(0);

        TreeNode *root = new TreeNode(t1->val + t2->val);
        root->left = this->mergeTrees(t1->left, t2->left);
        root->right = this->mergeTrees(t1->right, t2->right);
        
        return root;
    }
};
