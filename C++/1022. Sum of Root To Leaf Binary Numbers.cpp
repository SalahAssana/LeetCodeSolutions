class Solution {
public:
    int sumRootToLeaf(TreeNode* root)
    {
        int result = 0;
        func(root, result, 0);
        return result;
    }

    void func(TreeNode* node, int& result, int val)
    {
        if (node == NULL)
            return;

        val = (val << 1) | node->val;
        if (node->left == node->right) {
            result += val;
        }

        func(node->left, result, val);
        func(node->right, result, val);
    }
};
