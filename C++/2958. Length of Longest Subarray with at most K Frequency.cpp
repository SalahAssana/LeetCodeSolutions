class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        int max_len = 0;
        int left = 0, right = 0;
        int n = nums.size();
        unordered_map<int, int> freq;

        while (left <= right && right < n) {
            if (freq[nums[right]] + 1 <= k) {
                freq[nums[right]] += 1;
                max_len = max(max_len, right - left + 1);
                right += 1;
            } else {
                freq[nums[left++]] -= 1;
            }
        }

        return max_len;
    }
};
