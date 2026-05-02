class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        int last_inc = 0;
        int n = bits.size();
        for (int idx = 0; idx < n; ++idx) {
            last_inc = 1;
            if (bits[idx] == 1) {
                last_inc += 1;
                idx += 1;
            }
        }

        return last_inc == 1;
    }
};
