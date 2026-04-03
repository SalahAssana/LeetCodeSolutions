class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        int m = mat.size();
        int count = 0;
        int abs_diff = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                int a = mat[i][j], b = target[i][j];
                count += a - b;
                abs_diff += (a > b) * (a - b) + (b > a) * (b - a);
            }
        }

        if (count != 0)
            return false;
        if (abs_diff == 0)
            return true;

        for (int i = 0; i < 3; ++i) {
            rotate(mat);
            int abs_diff = 0;

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    int a = mat[i][j], b = target[i][j];
                    abs_diff += (a > b) * (a - b) + (b > a) * (b - a);
                }
            }

            if (abs_diff == 0)
                return true;
        }

        return false;
    }

    void rotate(vector<vector<int>>& mat)
    {
        int m = mat.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        int mid = m >> 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < mid; ++j) {
                int temp = mat[i][j];
                mat[i][j] = mat[i][m - j - 1];
                mat[i][m - j - 1] = temp;
            }
        }
    }
};
