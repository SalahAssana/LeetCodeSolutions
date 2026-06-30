class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word)
    {
        int result = 0;
        int n = word.size();

        for (auto& pattern : patterns) {
            int len = pattern.size();
            bool found = false;
            for (int offset = 0; offset <= n - len; ++offset) {
                found = strncmp(pattern.c_str(), word.c_str() + offset, len) == 0;
                if (found)
                    break;
            }

            result += found;
        }

        return result;
    }
};
