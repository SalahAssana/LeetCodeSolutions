class Solution {
public:
    vector<int> resultArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> arr1, arr2, result(n, 0);
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < n; ++i) {
            auto num = nums[i];

            if (arr1.back() > arr2.back()) {
                arr1.push_back(num);
            } else {
                arr2.push_back(num);
            }
        }

        int offset = 0;
        for (auto num : arr1) {
            result[offset++] = num;
        }

        for (auto num : arr2) {
            result[offset++] = num;
        }

        return result;
    }
};
