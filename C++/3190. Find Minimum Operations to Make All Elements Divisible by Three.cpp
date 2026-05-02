class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int result = 0;

        for (auto num : nums) {
            result += min(num % 3, 3 - (num % 3));
        }

        return result;
    }
};
