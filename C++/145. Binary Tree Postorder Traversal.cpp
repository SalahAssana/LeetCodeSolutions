
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        post(root, result);
        return result;
    }

    void post(TreeNode *node, vector<int>& result) {
        if (node == nullptr) return;

        post(node->left, result);
        post(node->right, result);

        result.push_back(node->val);
    } 
};
