class Solution {
public:
    int missingInteger(vector<int>& nums)
    {
        int num = nums[0];
        unordered_set<int> found(nums.begin(), nums.end());
        int n = nums.size();
        for (size_t end = 1; end < n && (nums[end - 1] + 1 == nums[end]); ++end) {
            num += nums[end];
        }

        while (found.find(num) != found.end())
            num += 1;
        return num;
    }
};
