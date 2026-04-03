class Solution {
public:
    const int _mod = 1000000000 + 7;
    int concatenatedBinary(int n)
    {
        int result = 0;
        for (int num = 1; num <= n; ++num) {
            int mask = get_mask(num);
            while (mask) {
                result = (result << 1) | ((num & mask) != 0);
                result %= _mod;
                mask = mask >> 1;
            }
        }
        return result;
    }

    inline int get_mask(int x)
    {
        return 1 << ((31) - __builtin_clz(x));
    }
};
