class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int digitSum = getDigitSum(nums[i]);
            if (digitSum == i) return i;
        }

        return -1;
    }

    int getDigitSum(int x) {
        int sum = 0;
        while(x) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }
};
