class Solution {
public:
    int mirrorDistance(int n)
    {
        int rev = reverse(n);
        return abs(n - rev);
    }

    int reverse(int x)
    {
        int res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
