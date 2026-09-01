class Solution {
public:
    int smallestNumber(int n, int t)
    {
        int start = n;
        while (true) {
            int prod = digit_product(start);
            if (is_divisible(prod, t))
                break;
            start += 1;
        }

        return start;
    }

    int digit_product(int x)
    {
        int prod = 1;
        while (x) {
            int digit = x % 10;
            x /= 10;
            prod *= digit;
        }
        return prod;
    }

    bool is_divisible(int n, int t)
    {
        int d = n / t;
        return d * t == n;
    }
};
