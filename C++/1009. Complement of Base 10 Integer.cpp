class Solution {
public:
    int bitwiseComplement(int n)
    {
        int result = 0;
        int offset = 0;
        if (n == 0)
            return 1;
        while (n) {
            int bit = (n & 1) == 0;
            n = n >> 1;
            result |= bit << offset;
            offset += 1;
        }
        return result;
    }
};
