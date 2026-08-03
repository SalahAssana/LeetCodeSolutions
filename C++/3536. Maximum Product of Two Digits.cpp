class Solution {
public:
    int maxProduct(int n)
    {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }

        sort(digits.begin(), digits.end());
        n = digits.size();
        return digits[n - 1] * digits[n - 2];
    }
};
