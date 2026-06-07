class Solution {
public:
    int minElement(vector<int>& nums)
    {
        int minResult = nums[0];
        for (auto& num : nums) {
            num = findDigitSum(num);
            minResult = min(num, minResult);
        }

        return minResult;
    }

    int findDigitSum(int num)
    {
        int result = 0;
        while (num) {
            result += num % 10;
            num /= 10;
        }

        return result;
    }
};
