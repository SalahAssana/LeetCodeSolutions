class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result = 0;
        int h = mat.size(), w = mat[0].size();
        for (int x = 0; x < w; ++x) {
            for (int y = 0; y < h; ++y) {
                if (mat[y][x] == 1) {
                    if (axis_sum(mat, x, y) == 2) {
                        result += 1;
                    }
                }
            }
        }

        return result;
    }

    int axis_sum(vector<vector<int>>& mat, int x, int y) {
        int h = mat.size(), w = mat[0].size();
        int sum = 0;

        for (int X = 0; X < w; ++X) {
            sum += mat[y][X];
        }

        for (int X = 0; X < h; ++X) {
            sum += mat[X][x];
        }

        return sum;
    }
};
