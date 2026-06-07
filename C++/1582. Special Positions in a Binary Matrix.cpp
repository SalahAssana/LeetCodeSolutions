class Solution {
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        int m = mat.size(), n = mat[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (sum == 1) {
                sum = 0;
                for (int j = 0; j < n; ++j) {
                    if (mat[i][j] == 1) {
                        for (int ii = 0; ii < m; ++ii) {
                            sum += mat[ii][j];
                        }

                        result += sum == 1;
                    }
                }
            }
        }
        return result;
    }
};
