class Solution {
public:
    int repeatedNTimes(vector<int>& nums)
    {
        unordered_map<int, int> counts;
        int n = nums.size() >> 1;
        for (auto num : nums) {
            counts[num] += 1;
            if (counts[num] == n)
                return num;
        }

        return 0;
    }
};
