class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> tri(numRows);
        for (int i = 1; i <= numRows; ++i) {
            vector<int>& row = tri[i - 1];
            row.resize(i, 1);
            if (i <= 2)
                continue;

            for (int j = 1; j < (i - 1); ++j) {
                row[j] = tri[i - 2][j - 1] + tri[i - 2][j];
            }
        }

        return tri;
    }
};
