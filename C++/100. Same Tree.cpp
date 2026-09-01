
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        stack<TreeNode*> s1, s2;
        s1.push(p);
        s2.push(q);

        while (s1.size() && s2.size()) {
            auto pp = s1.top();
            s1.pop();
            auto qp = s2.top();
            s2.pop();

            if (pp == qp)
                continue;
            else if (pp == nullptr && qp != nullptr)
                return false;
            else if (pp != nullptr && qp == nullptr)
                return false;
            else if (pp->val != qp->val)
                return false;

            s1.push(pp->left);
            s1.push(pp->right);
            s2.push(qp->left);
            s2.push(qp->right);
        }

        if (s1.size() || s2.size())
            return false;
        return true;
    }
};
