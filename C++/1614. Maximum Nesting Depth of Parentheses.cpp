class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int max_depth = 0;
        for (auto c : s) {
            depth += (c == '(') - (c == ')');
            max_depth = max(depth, max_depth);
        }

        return max_depth;
    }
};
