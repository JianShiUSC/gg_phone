/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root) {
        if(!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        if(left == 0) root->left = NULL;
        if(right == 0) root->right = NULL;
        return root->val + left + right;
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
