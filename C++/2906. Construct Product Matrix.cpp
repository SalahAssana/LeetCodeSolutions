class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        long long total = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = total;
                total = (total * grid[i][j]) % MOD;
            }
        }

        total = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = (dp[i][j] * total) % MOD;
                total = (total * grid[i][j]) % MOD;
            }
        }

        return dp;
    }
};
