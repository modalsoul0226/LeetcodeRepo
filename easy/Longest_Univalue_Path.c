/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max_len;

int find_path(struct TreeNode *curr, int target) {
        if (!curr) return 0;
        
        int left_len = find_path(curr->left, curr->val);
        int right_len = find_path(curr->right, curr->val);
        
        // printf("%d %d %d\n", left_len, right_len, max_len);
        max_len = max_len > left_len + right_len ? max_len : left_len + right_len;

        if (curr->val == target) {
            return left_len > right_len ? left_len + 1 : right_len + 1;
        } else return 0;
}

int longestUnivaluePath(struct TreeNode* root) {
    max_len = 0;
    find_path(root, NULL);
    return max_len;
}                