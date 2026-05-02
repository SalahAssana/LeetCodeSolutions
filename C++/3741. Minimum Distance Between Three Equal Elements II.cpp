class Solution {
public:
    int minimumDistance(vector<int>& nums)
    {
        int result = INT_MAX;
        int n = nums.size();

        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            m[num].push_back(i);
        }

        for (auto pair : m) {
            auto& indices = pair.second;
            int num = pair.first;

            int m = indices.size();

            if (m >= 3) {
                for (int t = 0; t < m - 2; ++t) {
                    int i = indices[t];
                    int j = indices[t + 1];
                    int k = indices[t + 2];

                    int dist = abs(i - j) + abs(j - k) + abs(k - i);
                    result = min(result, dist);
                }
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};
