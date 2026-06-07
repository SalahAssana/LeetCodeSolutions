class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_set<int> prefixes;
        int max_num = 0;

        sort(arr2.begin(), arr2.end(), std::greater<int>());

        for (auto num : arr1) {
            while (num) {
                prefixes.insert(num);
                num /= 10;
            }
        }

        for (auto num : arr2) {
            while (num) {
                if (num <= max_num)
                    break;
                if (prefixes.find(num) != prefixes.end())
                    max_num = max(max_num, num);
                num /= 10;
            }
        }

        int result = 0;
        while (max_num) {
            result += 1;
            max_num /= 10;
        }

        return result;
    }
};
