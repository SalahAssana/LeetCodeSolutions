class Solution {
public:
    int maxDistance(vector<int>& colors)
    {
        int result = 0;
        int n = colors.size();

        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j > i; --j) {
                if (colors[j] != colors[i]) {
                    result = max(j - i, result);
                }
            }
        }

        return result;
    }
};
