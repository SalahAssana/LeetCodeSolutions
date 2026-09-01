class Solution {
public:
    bool checkDivisibility(int n)
    {
        int prod = 1, sum = 0;
        int temp = n;
        while (temp) {
            int digit = temp % 10;
            temp /= 10;

            prod *= digit;
            sum += digit;
        }

        return n % (sum + prod) == 0;
    }
};
