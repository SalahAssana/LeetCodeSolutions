class Solution {
public:
    long long gcdSum(vector<int>& nums)
    {
        long long result = 0;
        int n = nums.size();
        int mx = 0;
        vector<int> prefixGcd(n, 0);
        for (size_t i = 0; i < n; ++i) {
            mx = max(nums[i], mx);
            prefixGcd[i] = __gcd(nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());

        for (size_t i = 0; i < n / 2; ++i) {
            result += __gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }

        return result;
    }
};
