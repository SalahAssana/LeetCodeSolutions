class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int h = mat.size(), w = mat[0].size();
        vector<vector<int>> ps(h+1, vector<int>(w+1, 0));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                ps[i+1][j+1] = mat[i][j]
                            + ps[i][j+1]
                            + ps[i+1][j]
                            - ps[i][j];
            }
        }
        
        int max_size = 0;
        for (int x = 0; x < w; ++x) {
            for (int y = 0; y < h; ++y) {
                int offset = min(w-x, h-y);
                int m = offset;
                if (offset < max_size) continue;
                while(offset) {
                    int val = get_sum(ps, x, y, offset-1);
                    if (val <= threshold) {
                        max_size = max(max_size, offset);
                        if (max_size == min(w, h)) return max_size;
                        break;
                    } 

                    offset = offset-1;
                }
            }
        }
        return max_size;
    }

    int get_sum(vector<vector<int>>& ps, int x, int y, int w) {
        int ex = x + w , ey = y + w;
        return ps[ey+1][ex+1]
            - ps[y][ex+1]
            - ps[ey+1][x]
            + ps[y][x];
    }
};
