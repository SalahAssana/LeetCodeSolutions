class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums)
    {
        vector<int> result;
        unordered_set<int> present;
        int mi = nums[0], ma = nums[0];
        for (auto num : nums) {
            mi = min(mi, num);
            ma = max(ma, num);
            present.insert(num);
        }

        for (int i = mi; i <= ma; ++i) {
            if (present.find(i) == present.end())
                result.push_back(i);
        }

        return result;
    }
};
