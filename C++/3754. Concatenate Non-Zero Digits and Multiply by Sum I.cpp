class Solution {
public:
    long long sumAndMultiply(int n)
    {
        long long x = 0;
        long long sum = 0;

        while (n) {
            int digit = n % 10;
            if (digit > 0) {
                x *= 10;
                x += digit;
            }
            sum += digit;
            n /= 10;
        }

        long long xrev = 0;
        while (x) {
            xrev *= 10;
            xrev += x % 10;
            x /= 10;
        }

        return xrev * sum;
    }
};
