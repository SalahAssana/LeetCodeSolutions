class Solution {
public:
    bool check(vector<int>& nums)
    {
        int n = nums.size();
        int offset = 0;
        for (offset = 1; offset < n; ++offset) {
            if (nums[offset - 1] > nums[offset])
                break;
        }

        for (int i = 0; i < n - 1; ++i) {
            int l = nums[(i + offset) % n];
            int r = nums[(i + offset + 1) % n];

            if (l > r)
                return false;
        }

        return true;
    }
};
