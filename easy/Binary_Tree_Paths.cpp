#include <vector>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        auto res = vector<string>();
        
        if (!root) return res;
        if (!root->left && !root->right) {
            res.push_back(to_string(root->val));
            return res;
            
        } else {
            for (auto path: binaryTreePaths(root->left)) {
                path = "->" + path;
                path = to_string(root->val) + path;
                res.push_back(path);
            }
            
            for (auto path: binaryTreePaths(root->right)) {
                path = "->" + path;
                path = to_string(root->val) + path;
                res.push_back(path);
            }
        }
        return res;
    }
};