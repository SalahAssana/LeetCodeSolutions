/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxProduct(TreeNode* root)
    {
        tree_prefix_sum(root);
        int total_sum = root->val;
        long long result = 0;
        const long long mod = 1e9 + 7;

        stack<TreeNode*> s;
        s.push(root);

        while (s.size()) {
            auto node = s.top();
            s.pop();
            int val = node->val;
            long long product = (long long)(total_sum - val) * val;
            result = max(result, product);

            if (node->left)
                s.push(node->left);
            if (node->right)
                s.push(node->right);
        }

        return result % mod;
    }

    void tree_prefix_sum(TreeNode* node)
    {
        if (node == NULL)
            return;

        tree_prefix_sum(node->left);
        tree_prefix_sum(node->right);

        if (node->left)
            node->val += node->left->val;
        if (node->right)
            node->val += node->right->val;
    }
};
