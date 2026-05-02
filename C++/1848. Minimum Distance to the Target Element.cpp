class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start)
    {
        int result = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                result = min(result, abs(i - start));
            }
        }
        return result;
    }
};
