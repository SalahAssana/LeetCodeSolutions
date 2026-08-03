class Solution {
public:
    int findGCD(vector<int>& nums)
    {
        int small = nums[0], big = nums[0];
        for (auto num : nums) {
            small = min(small, num);
            big = max(big, num);
        }

        return __gcd(small, big);
    }
};
