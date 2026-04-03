class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1, 0));

        vector<int> temp(k * k, 0);
        for (int y = 0; y <= m - k; ++y) {
            for (int x = 0; x <= n - k; ++x) {

                for (int i = 0; i < k; ++i) {
                    for (int j = 0; j < k; ++j) {
                        temp[i * k + j] = grid[y + i][x + j];
                    }
                }
                sort(temp.begin(), temp.end());
                int abs_min = INT_MAX;
                for (int i = 0; i < k * k - 1; ++i) {
                    int diff = temp[i + 1] - temp[i];
                    if (diff != 0) {
                        abs_min = min(abs_min, diff);
                    }
                }
                result[y][x] = abs_min * (abs_min != INT_MAX);
            }
        }

        return result;
    }
};
