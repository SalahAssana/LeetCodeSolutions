class Solution {
public:
    int minimumDeletions(vector<int>& nums)
    {
        int min_idx = 0, max_idx = 0;
        int result = 0;
        int n = nums.size();

        if (n <= 2)
            return n;

        for (int i = 0; i < n; ++i) {
            if (nums[min_idx] < nums[i]) {
                min_idx = i;
            } else if (nums[max_idx] > nums[i]) {
                max_idx = i;
            }
        }

        int left = min(min_idx, max_idx);
        int right = max_idx + min_idx - left;

        int m1 = right + 1;
        int m2 = n - left;
        int m3 = left + 1 + n - right;

        result = min({ m1, m2, m3 });

        return result;
    }
};
