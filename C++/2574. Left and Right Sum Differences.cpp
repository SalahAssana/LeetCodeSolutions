class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums)
    {
        vector<int> prefix_sum = nums;
        int n = prefix_sum.size();
        vector<int> result(n, 0);

        for (int i = 1; i < n; ++i) {
            prefix_sum[i] += prefix_sum[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            int left = 0, right = 0;
            if (i > 0)
                left = prefix_sum[i - 1];
            if (i < n - 1)
                right = prefix_sum[n - 1] - prefix_sum[i];

            result[i] = abs(left - right);
        }

        return result;
    }
};
