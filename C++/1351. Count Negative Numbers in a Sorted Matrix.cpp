class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int result = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 0; --j) {
                result += grid[i][j] < 0;
            }
        }

        return result;
    }
};
