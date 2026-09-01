
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);

        while (s.size()) {
            TreeNode* node = s.top();
            s.pop();

            if (node == nullptr)
                continue;
            TreeNode* left = node->left;
            TreeNode* right = node->right;

            result.push_back(node->val);
            if (right)
                s.push(right);
            if (left)
                s.push(left);
        }

        return result;
    }
};
