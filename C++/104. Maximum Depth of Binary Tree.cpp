class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        int result = dfs(root);
        return result;
    }

    int dfs(TreeNode* node, int level = 0)
    {
        if (node == nullptr)
            return level;
        return max(dfs(node->left, level + 1), dfs(node->right, level + 1));
    }
};
