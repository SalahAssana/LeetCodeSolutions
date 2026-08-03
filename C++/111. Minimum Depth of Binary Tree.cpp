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
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return min_depth(root);
    }

    int min_depth(TreeNode* node, int level = 1)
    {
        if (node == nullptr)
            return INT_MAX;
        if (node->left == nullptr && node->right == nullptr)
            return level;

        int min_level = INT_MAX;
        if (node->left != nullptr)
            min_level = min(min_level, min_depth(node->left, level + 1));
        if (node->right != nullptr)
            min_level = min(min_level, min_depth(node->right, level + 1));

        return min_level;
    }
};
