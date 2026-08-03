class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        auto dp = triangle;
        int n = triangle.size();

        for (int row = 1; row < n; ++row) {
            auto& top = dp[row - 1];
            auto& cur = dp[row];

            int w = cur.size();
            for (int i = 0; i < w; ++i) {
                if (i == 0)
                    cur[i] = top[i] + triangle[row][i];
                else if (i == w - 1)
                    cur[i] = top[i - 1] + triangle[row][i];
                else {
                    cur[i] = min(top[i] + triangle[row][i], top[i - 1] + triangle[row][i]);
                }
            }
        }

        int result = INT_MAX;
        for (auto num : dp.back()) {
            result = min(result, num);
        }

        return result;
    }
};
