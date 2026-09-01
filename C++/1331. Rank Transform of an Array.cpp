class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        set<int> elements(arr.begin(), arr.end());
        unordered_map<int, int> ranks;
        int i = 0;
        for (auto num : elements) {
            ranks[num] = ++i;
        }

        vector<int> result = arr;
        for (auto& num : result) {
            num = ranks[num];
        }

        return result;
    }
};
