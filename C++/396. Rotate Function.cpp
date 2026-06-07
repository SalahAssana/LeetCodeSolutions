class Solution {
public:
    int maxRotateFunction(vector<int>& nums)
    {
        int n = nums.size();
        int result = -INT_MAX;
        int num_sum = accumulate(nums.begin(), nums.end(), 0);
        int f = 0;

        for (int i = 0; i < n; ++i) {
            f += i * nums[i];
        }
        result = f;

        for (int k = 1; k < n; ++k) {
            f = f + num_sum - n * nums[n - k];
            result = max(result, f);
        }

        return result;
    }
};
