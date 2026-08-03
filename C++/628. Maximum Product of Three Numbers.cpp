class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int result = -1000 * -1000 * -1000 - 1;
        for (int i = 0; i < 3; ++i) {
            int num = nums[(n - 3 + i) % n] * nums[(n - 2 + i) % n] * nums[(n - 1 + i) % n];
            result = max(num, result);
        }

        return result;
    }
};
