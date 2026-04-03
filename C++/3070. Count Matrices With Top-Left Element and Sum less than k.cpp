class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));

        // Prefix sum
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + grid[i][j];
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (submatrix_sum(ps, 0, 0, i, j) <= k)
                    result += 1;
            }
        }
        return result;
    }

    int submatrix_sum(vector<vector<int>>& psa, int c1, int r1, int c2, int r2)
    {
        int sum = psa[c2 + 1][r2 + 1] - psa[c1][r2 + 1] - psa[c2 + 1][r1] + psa[c1][r1];
        return sum;
    }
};
