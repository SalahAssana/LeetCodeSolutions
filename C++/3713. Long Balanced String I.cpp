class Solution {
public:
    int longestBalanced(string s)
    {
        vector<int> ocounts(26, 0);
        int n = s.size();
        for (auto c : s) {
            ocounts[c - 'a'] += 1;
        }
        int width = 0;
        for (width = n; width > 0; --width) {
            auto counts = ocounts;
            int end = n - width + 1;
            for (int i = width; i < n; ++i)
                counts[s[i] - 'a'] -= 1;
            for (int i = 0; i < end; ++i) {
                if (i > 0)
                    counts[s[i - 1] - 'a'] -= 1;
                if (is_balanced(counts))
                    return width;
                if (i + width < n)
                    counts[s[i + width] - 'a'] += 1;
            }
        }

        return width;
    }

    bool is_balanced(const vector<int>& counts)
    {
        int count = -1;
        for (int i = 0; i < 26; i += 1) {
            if (count == -1 && counts[i] != 0)
                count = counts[i];
            if (count != counts[i] && counts[i] != 0)
                return false;
        }
        return true;
    }
};
