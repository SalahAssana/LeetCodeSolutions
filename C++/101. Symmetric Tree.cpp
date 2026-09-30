class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return symmetryCheck(root->left, root->right);
    }

    bool symmetryCheck(TreeNode* left, TreeNode* right) {
        if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right != nullptr) return false;
        
        if (left == right) return true;

        if (left->val != right->val) return false;

        if (symmetryCheck(left->left, right->right) == false) return false;
        else if (symmetryCheck(left->right, right->left) == false) return false;

        return true;
    } 
};
