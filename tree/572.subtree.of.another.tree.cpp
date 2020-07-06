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
    vector<TreeNode *> s_nodes;
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        int h = this->height(t);
        
        // get nodes at depth h
        this->get_nodes_at_depth_k(s, h);

        // check if same tree
        for (const auto node: this->s_nodes)
            if (this->isSameTree(node, t))
                return true;
        
        return false;
    }
    
    bool isSameTree(TreeNode *t1, TreeNode *t2) {
        // if one or more nodes are null
        if (!(t1 || t2))
            return true;
        else if (!t1 || !t2)
            return false;
        
        // if both nodes exist
        if (!(t1->val == t2->val))
            return false;
        
        return this->isSameTree(t1->left, t2->left) && this->isSameTree(t1->right, t2->right);
    }

    /**
     * Get the height of a tree.
     */
    int height(TreeNode *n) {
        if (!n) return 0;
        
        return 1 + max(this->height(n->left), this->height(n->right));
    }

    /**
     * Get the nodes at a specific depth k.
     */
    int get_nodes_at_depth_k(TreeNode *t, int k) {
        if (!t) return 0;
        
        int depth = 1 + max(this->get_nodes_at_depth_k(t->left, k), this->get_nodes_at_depth_k(t->right, k));
        
        if (depth == k) this->s_nodes.push_back(t);
        return depth;
    }
};
