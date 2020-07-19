#include <bits/stdc++.h>
#include "leetcode.hpp"

using namespace std;

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        // a stack of nodes
        stack<TreeNode *> nodes;
        // minimum value of the tree
        int minVal = root->val;
        int secondMin = 0;
        
        // init stack
        nodes.push(root);

        // traverse
        while (!nodes.empty()) {
            // extract a node
            TreeNode *node = nodes.top();
            nodes.pop();

            // if it's larger than minimum, then it's a candidate
            if (node->val > minVal) {
                secondMin = secondMin ? min(secondMin, node->val) : node->val;
                continue;
            }

            // if no child nodes
            if (!node->left)
                continue;

            if (node->right->val > node->left->val) {
                nodes.push(node->right);
                nodes.push(node->left);
            } else {
                nodes.push(node->left);
                nodes.push(node->right);
            }
        }

        return secondMin ? secondMin : -1;
    }
};

int main() {
    vector<int> vect{1,1,3,1,1,3,4,3,1,1,8};
    auto root = vec2tree(vect, 0);

    auto sol = new Solution();
    cout << sol->findSecondMinimumValue(root) << endl;
}
