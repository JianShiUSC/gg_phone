struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(vector<int>& res, TreeNode* root, int lowerBound, int higherBound) {
    if(!root) return;
    if(root->val >= lowerBound && root->val <= higherBound) {
        res.push_back(root->val);
        helper(res, root->left, lowerBound, higherBound);
        helper(res, root->right, lowerBound, higherBound);
    } else if(root->val < lowerBound) {
        helper(res, root->right, lowerBound, higherBound);
    } else {
        helper(res, root->left, lowerBound, higherBound);
    }
}

vector<int> bst(TreeNode* root, int lowerBound, int higherBound) {
    vector<int> res;
    if(!root) return res;
    helper(res, root, lowerBound, higherBound);
    return res;
}

int main() {
    TreeNode* p1 = new TreeNode(4);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p3 = new TreeNode(6);
    TreeNode* p4 = new TreeNode(1);
    TreeNode* p5 = new TreeNode(3);
    TreeNode* p6 = new TreeNode(5);
    TreeNode* p7 = new TreeNode(7);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    bst(p1, 0, 10);
}




vector<int> bst(TreeNode* root, int lowerBound, int higherBound) {
    vector<int> res;
    if(!root) return res;

    queue<TreeNode*> qu;
    qu.push(root);

    while(!qu.empty()) {
        TreeNode* temp = qu.front();
        qu.pop();
        if(temp->val >= lowerBound && temp->val <= higherBound) {
            res.push_back(temp->val);
            // prune
            if(temp->val == lowerBound && temp->val == higherBound) break;
            else if(temp->val == lowerBound && temp->right) {
                qu.push(temp->right);
            } else if(temp->val == higherBound && temp->left) {
                qu.push(temp->left);
            } else {    // temp->val in the middle of lowerBound and higherBound
                if(temp->left) {
                    qu.push(temp->left);
                }
                if(temp->right) {
                    qu.push(temp->right);
                }
            }
        } else if(temp->val < lowerBound) {
            if(temp->right) {
                qu.push(temp->right);
            }
        } else {
            if(temp->left) {
                qu.push(temp->left);
            }
        }
    }
    return res;
}

int main() {
    TreeNode* p1 = new TreeNode(4);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p3 = new TreeNode(6);
    TreeNode* p4 = new TreeNode(1);
    TreeNode* p5 = new TreeNode(3);
    TreeNode* p6 = new TreeNode(5);
    TreeNode* p7 = new TreeNode(7);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    bst(p1, 1, 10);
}
