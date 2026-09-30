class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxv(n, 0), minv(n, 1e9);
        maxv[0] = nums[0];
        minv[n-1] = nums[n-1];
        for (int i = 1; i < n; ++i) {
            maxv[i] = max(maxv[i-1], nums[i]);
            minv[n-i-1] = min(minv[n-i], nums[n-i-1]);
        }

        for (int i = 0; i < n; ++i) {
            if (maxv[i]-minv[i] <= k) return i;
        }

        return -1;
    }
};
