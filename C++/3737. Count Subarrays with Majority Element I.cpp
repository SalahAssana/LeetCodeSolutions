class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + (target == nums[i - 1]);
        }

        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; ++j) {
                int len = j - i;
                int counts = prefix[j] - prefix[i];
                result += (2 * counts > len);
            }
        }

        return result;
    }
};
