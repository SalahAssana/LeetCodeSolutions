class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        int result = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int rem = sum % k;

        return rem;
    }
};
