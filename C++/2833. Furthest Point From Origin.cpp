class Solution {
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int result = 0;
        char cur = 'L';
        int dist = 0;
        for (auto move : moves) {
            dist += (move == 'L') - (move == 'R');
        }

        if (dist < 0)
            dist = -1;
        else if (dist >= 0)
            dist = 1;

        for (auto move : moves) {
            result += (move == 'L') - (move == 'R') + dist * (move == '_');
        }

        return abs(result);
    }
};
