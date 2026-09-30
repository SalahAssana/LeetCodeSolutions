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
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        getSubtreeSumAndCount(root, result);
        return result;
    }

    vector<int> getSubtreeSumAndCount(TreeNode* root, int& result) {
        if (root == nullptr) return {0, 0};
        vector<int> left = getSubtreeSumAndCount(root->left, result);
        vector<int> right = getSubtreeSumAndCount(root->right, result);

        int count = 1 + left[1] + right[1];
        int sum = root->val + left[0] + right[0];
        int avg = sum / count;

        result += avg == root->val;
        return {sum, count};
    }
};
