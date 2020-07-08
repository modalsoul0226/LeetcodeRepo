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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        return this->isSymmetric(root->left, root->right);
    }

    /**
     * Check whether two trees are symmetric.
     */
    bool isSymmetric(TreeNode *t1, TreeNode *t2) {
        // one or more nodes are null
        if (!(t1 || t2)) return true;
        if (!t1 || !t2) return false;

        // check root
        if (t1->val != t2->val)
            return false;

        // check subtrees
        return this->isSymmetric(t1->left, t2->right) && this->isSymmetric(t1->right, t2->left);
    }
};
