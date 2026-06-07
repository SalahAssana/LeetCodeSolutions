class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid)
    {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> result(n, vector<char>(m, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[j][i] = boxGrid[m - 1 - i][j];
            }
        }

        for (int x = 0; x < m; ++x) {
            int bottom = n;
            for (int y = n - 1; y >= 0; --y) {
                switch (result[y][x]) {
                case '*':
                    bottom = y;
                    break;
                case '#': {
                    result[y][x] = '.';
                    result[bottom - 1][x] = '#';
                    bottom = bottom - 1;
                    break;
                }
                }
            }
        }

        return result;
    }
};
