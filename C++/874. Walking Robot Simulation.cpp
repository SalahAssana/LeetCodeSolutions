class Solution {
public:
    const vector<char> directions = { 'N', 'E', 'S', 'W' };

    uint64_t encode(int x, int y)
    {
        return ((uint32_t)x | ((uint64_t)(uint32_t)y << 32));
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int dir = 0;
        auto cur_pos = make_pair(0, 0);
        int moved = 0;
        int result = 0;

        unordered_set<uint64_t> obss;
        for (auto& o : obstacles) {
            auto e = encode(o[0], o[1]);
            obss.insert(e);
        }

        for (auto command : commands) {
            if (command < 0) {
                dir += (command == -1) - (command == -2);
                dir += ((dir < 0) - (dir > 3)) * 4;
            }

            char d = directions[dir];
            if (command >= 1) {

                int k = command;
                for (int i = 0; i < k; ++i) {
                    cur_pos.second += ((d == 'N') - (d == 'S'));
                    cur_pos.first += ((d == 'E') - (d == 'W'));

                    auto e = encode(cur_pos.first, cur_pos.second);
                    if (obss.find(e) != obss.end()) {
                        cur_pos.second -= ((d == 'N') - (d == 'S'));
                        cur_pos.first -= ((d == 'E') - (d == 'W'));
                        break;
                    }
                }
                result = max(cur_pos.first * cur_pos.first + cur_pos.second * cur_pos.second, result);
            }

            moved += 1;
        }

        return result;
    }
};
