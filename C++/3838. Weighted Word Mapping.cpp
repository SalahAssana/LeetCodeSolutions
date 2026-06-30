class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights)
    {
        string result;
        for (auto word : words) {
            int sum = 0;
            for (auto c : word) {
                int offset = c - 'a';
                sum += weights[offset];
            }

            sum %= 26;
            result += 'z' - sum;
        }

        return result;
    }
};
