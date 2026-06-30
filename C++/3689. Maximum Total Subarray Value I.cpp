class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k)
    {
        long long max_val = 0;
        long long min_val = INT_MAX;

        for (auto num : nums) {
            max_val = max(max_val, (long long)num);
            min_val = min(min_val, (long long)num);
        }

        return (max_val - min_val) * k;
    }
};
