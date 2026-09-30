class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; ++i) {
            result[(i+k)%n] = nums[i];
        }

        nums = result;
    }
};
