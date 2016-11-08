class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int path = 0;
        getSum(root, sum, path);
        return sum;
    }

    void getSum(TreeNode* root, int& sum, int path) {
        if(!root) return;
        path = path * 10 + root->val;
        if(!root->left && !root->right) sum += path;
        getSum(root->left, sum, path);
        getSum(root->right, sum, path);
    }
};
