#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



void build_tree(vector<int> list, int i, TreeNode *node) {
    int l = i * 2 - 1, r = l + 1;
    // printf("%d ", node->val);

    if (l < list.size() && list[l] != -1) {
        node->left = new TreeNode(list[l]);
        build_tree(list, l + 1, node->left);
    }
    if (r < list.size() && list[r] != -1) {
        node->right = new TreeNode(list[r]);
        build_tree(list, r + 1, node->right);
    }
}

void print_tree(TreeNode *node) {
    printf("%d ", node->val);

    if (node->left)
        print_tree(node->left);
    if (node->right)
        print_tree(node->right);
}

class Solution {
public:
    set<TreeNode *> ancestors; TreeNode *res;
    
    int dfs1(TreeNode *root, TreeNode *p) {
        if (root->val == p->val) {
            ancestors.insert(root);
            return 1;
        }
        
        if (!root->left && !root->right)
            return 0;
        
        int ok = 0;
        if (root->left) ok += dfs1(root->left, p);
        if (root->right) ok += dfs1(root->right, p);
        
        if (ok)
            ancestors.insert(root);
        else
            return 0;
        return 1;
    }
    
    
    int dfs2(TreeNode *root, TreeNode *q) {
        if (root->val == q->val) {
            if (ancestors.count(root))
                res = root;
            
            return 1;
        }
        
        if (!root->left && !root->right)
            return 0;
        
        int ok = 0;
        if (root->left) ok += dfs2(root->left, q);
        if (root->right) ok += dfs2(root->right, q);
        
        if (ok)
            res = (!res && ancestors.count(root)) ? root : res;
        else
            return 0;
        return 1;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // ancestors = set<TreeNode *>();
        // res = nullptr;
        
        // dfs1(root, p);
        // dfs2(root, q);
        // return res;
        if (!root || root->val == p->val || root->val == q->val)
            return root;
        
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};

int main() {
    auto sol = Solution();
    int list[] = {3,5,1,6,2,0,8,-1,-1,7,4};
    vector<int> nodes(list, list + 11);
    for (auto each: nodes) printf("%d ", each); printf("\n");

    TreeNode *root = new TreeNode(3);
    build_tree(nodes, 1, root);

    auto ans = sol.lowestCommonAncestor(root, new TreeNode(5), new TreeNode(4));
    printf("ans: %d\n", ans->val);
}