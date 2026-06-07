class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        bool s = n & 0x1;
        while (n) {
            bool d = n & 0x1;
            if (d != s)
                return false;
            else
                s = !s;

            n = n >> 1;
        }
        return true;
    }
};
