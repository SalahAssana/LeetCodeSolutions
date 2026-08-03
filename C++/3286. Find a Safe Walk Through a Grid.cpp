class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        deque<vector<int>> dq;
        dq.push_front({ 0, 0, health });

        while (dq.size()) {
            auto coord = dq.front();
            dq.pop_front();
            int r = coord[0];
            int c = coord[1];
            int cur_health = coord[2];

            cur_health -= grid[r][c];
            if (cur_health == 0)
                continue;
            if (r == n - 1 && c == m - 1 && health > 0)
                return true;

            for (auto& [dr, dc] : dirs) {
                int nr = dr + r;
                int nc = dc + c;

                if (!isWithinBounds(nr, nc, n, m) || visited[nr][nc])
                    continue;
                int next = grid[nr][nc];

                if (next == 1)
                    dq.push_back({ nr, nc, cur_health });
                else
                    dq.push_front({ nr, nc, cur_health });

                visited[nr][nc] = 1;
            }
        }

        return false;
    }

private:
    vector<pair<int, int>> dirs = {
        make_pair(1, 0), make_pair(0, 1),
        make_pair(-1, 0), make_pair(0, -1)
    };

    bool isWithinBounds(int r, int c, int n, int m)
    {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }
};
