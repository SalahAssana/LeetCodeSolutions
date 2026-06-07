class Solution {
public:
    bool isGood(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max_num = nums[n - 1];

        if (max_num + 1 != n)
            return false;

        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] != i)
                return false;
        }

        return nums[n - 1] == max_num;
    }
};
