
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<pair<TreeNode*, int>> q;
        if (root == nullptr) return false;
        q.push(make_pair(root, 0));
        while(q.size()) {
            auto [node, sum] = q.front(); q.pop();

            if (node->left == node->right && (node->val + sum) == targetSum) return true;

            if (node->left != nullptr)
                q.push(make_pair(node->left, node->val + sum));
            if (node->right != nullptr)
                q.push(make_pair(node->right, node->val + sum));
        }
        return false;
    }
};
