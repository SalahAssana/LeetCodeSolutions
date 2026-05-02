class Solution {
public:
    int minimumDistance(vector<int>& nums)
    {
        int result = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (
                        nums[i] == nums[j] && nums[j] == nums[k]) {
                        result = min(result,
                            abs(i - j) + abs(j - k) + abs(k - i));
                    }
                }
            }
        }

        return result != INT_MAX ? result : -1;
    }
};
