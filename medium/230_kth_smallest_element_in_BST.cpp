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
    int kthSmallest(TreeNode* root, int k) {
        int acc = 0; stack<TreeNode *> S;
        auto p = root;
        
        while (!(S.empty()) || p) {
            if (p) {
                S.push(p);
                p = p->left;
            } else {
                auto node = S.top(); S.pop();
                acc++;
                
                if (acc == k) return node->val;
                p = node->right;
            }
        }
    }
};

int main() {
    auto root = new TreeNode(1);
    auto sol = Solution();

    cout << sol.kthSmallest(root, 1) << endl;

    return 0;
}
