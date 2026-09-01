class Solution {
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        string result = "";
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        for (size_t i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + (s[i - 1] == '1');
        }

        for (size_t i = 0; i <= n; ++i) {
            for (size_t j = i; j <= n; ++j) {
                if (result != "" && (j - i) > result.size())
                    continue;
                if (prefix[j] - prefix[i] == k) {
                    string found(s.c_str() + i, s.c_str() + j);
                    if (result == "" || smallerLex(found, result)) {
                        result = std::move(found);
                    }
                }
            }
        }

        return result;
    }

    inline bool smallerLex(const std::string& left, const std::string& right)
    {
        if (left.size() < right.size())
            return true;
        else if (left.size() > right.size())
            return false;
        else
            return left < right;
    }
};
