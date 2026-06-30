class Solution {
public:
    int binaryGap(int n)
    {
        int result = 0;
        int gap = 0;
        while (n) {
            int bit = n & 1;
            n = n >> 1;
            if (bit) {
                result = max(gap, result);
                gap = 1;
            } else
                gap += (gap != 0);
        }

        return result;
    }
};
