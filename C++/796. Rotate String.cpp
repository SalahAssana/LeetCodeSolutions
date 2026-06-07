class Solution {
public:
    bool rotateString(string s, string goal)
    {
        int n = s.size();
        int m = goal.size();
        if (n != m)
            return false;

        int i = 0, j = 0;

        for (j = 0; j < n; ++j) {
            if (s[j] == goal[0]) {
                for (i = 0; i < n; ++i) {
                    if (s[(i + j) % n] != goal[i])
                        break;
                }

                if (i == n)
                    return true;
            }
        }

        return false;
    }
};
