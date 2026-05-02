class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        double result = 0.0f;

        vector<vector<double>> tower = { { (double)poured } };
        for (int i = 0; i <= query_row; ++i) {
            int n = tower.back().size();
            tower.push_back(vector<double>(n + 1, 0.0f));
        }

        int h = tower.size();
        for (int i = 1; i < h; ++i) {
            auto& above = tower[i - 1];
            auto& row = tower[i];

            int w = above.size();
            for (int j = 0; j < w; ++j) {
                double excess = above[j] - 1.0f;
                if (excess > 0.0f) {
                    above[j] = 1.0f;
                    row[j] += excess / 2;
                    row[j + 1] += excess / 2;
                }
            }
        }

        result = tower[query_row][query_glass];
        return result;
    }
};
