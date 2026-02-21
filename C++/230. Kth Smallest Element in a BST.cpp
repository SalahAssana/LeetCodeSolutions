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
class Solution
{
public:
    vector<int> inorder(TreeNode* currentNode, vector<int> &arr)
    {
        if (currentNode == nullptr) return arr;
        inorder(currentNode->left, arr);
        arr.push_back(currentNode->val);
        inorder(currentNode->right, arr);
        return arr;
    }
    int kthSmallest(TreeNode* root, int k)
    {
        vector<int> arr;
        vector<int> solution = inorder(root, arr);
        return solution[k-1];
    }
};