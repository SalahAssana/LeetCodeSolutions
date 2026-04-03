class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return true;

        for(int i = 0; i < (n-2*k+1); ++i) {
            int a = i;
            int b = i + k;

            int j = 0;
            for(j = 0; j < k-1; ++j) {
                if (nums[a+j] >= nums[a+j+1] || nums[b+j] >= nums[b+j+1])
                    break;
            }

            if (j == k-1) return true;
        }
        return false;
    }
};
