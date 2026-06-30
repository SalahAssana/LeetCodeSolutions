class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        unordered_map<int, TreeNode*> node_maps;
        unordered_map<int, int> child_parent_maps;
        int result = 0;

        for (auto& description : descriptions) {
            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];

            if (result == 0)
                result = parent;
            if (child == result)
                result = parent;

            child_parent_maps[child] = parent;

            if (node_maps[parent] == NULL)
                node_maps[parent] = new TreeNode(parent);
            if (node_maps[child] == NULL)
                node_maps[child] = new TreeNode(child);

            if (isLeft)
                node_maps[parent]->left = node_maps[child];
            else
                node_maps[parent]->right = node_maps[child];
        }

        while (child_parent_maps[result] != 0)
            result = child_parent_maps[result];
        return node_maps[result];
    }
};
