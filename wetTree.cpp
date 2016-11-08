struct TreeNode {
    int val;
    int weight;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, int y) : val(x), weight(y), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestPath(TreeNode* root) {
        return findLongestPath(root);
    }

    int findLongestPath(TreeNode* root) {
        if(!root) return 0;
        int left = findLongestPath(root->left);
        int right = findLongestPath(root->right);
        return root->weight + (left > right ? left : right);
    }
};

int main() {
    TreeNode* root = new TreeNode(1, 0);
    TreeNode* p1 = new TreeNode(1, 1);
    TreeNode* p2 = new TreeNode(1, 2);
    TreeNode* p3 = new TreeNode(1, 10);
    TreeNode* p4 = new TreeNode(1, 5);
    TreeNode* p5 = new TreeNode(1, 4);
    TreeNode* p6 = new TreeNode(1, 20);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    Solution sol;
    cout << sol.longestPath(root) << endl;
}
