class Solution {
public:
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;
        for (auto d : moves) {
            x += ((d == 'L') * -1) + (d == 'R');
            y += (d == 'U') + ((d == 'D') * -1);
        }

        return x == 0 && y == 0;
    }
};
