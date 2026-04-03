class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k)
    {
        int result = 0;
        int cur_num = 0;
        int count = 0;
        sort(nums.begin(), nums.end());

        for (const auto& num : nums) {
            if (num != cur_num) {
                if (count % k == 0) {
                    result += cur_num * count;
                }
                cur_num = num;
                count = 0;
            }
            count++;
        }

        if (count % k == 0) {
            result += cur_num * count;
        }
        return result;
    }
};
