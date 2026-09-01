class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)
    {
        set<int> s(nums.begin(), nums.end());
        int m = 1;
        while (true) {
            int to_find = m * k;
            if (s.find(to_find) == s.end()) {
                return to_find;
            }
            m++;
        }
        return m * k;
    }
};
