class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int n = arr.size();

        int min_diff = arr[1] - arr[0];

        for (int i = 0; i < n - 1; ++i) {
            min_diff = min(min_diff, arr[i + 1] - arr[i]);
        }

        for (int i = 0; i < n - 1; ++i) {
            int diff = arr[i + 1] - arr[i];
            if (diff == min_diff) {
                result.push_back({ arr[i], arr[i + 1] });
            }
        }

        return result;
    }
};
