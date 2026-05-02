class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int ni = (i + num) % n;
            if (ni < 0)
                ni += n;

            result[i] = nums[ni];
        }

        return result;
    }
};
