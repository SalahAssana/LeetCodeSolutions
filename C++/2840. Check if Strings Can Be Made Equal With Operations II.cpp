class Solution {
public:
    bool checkStrings(string s1, string s2)
    {
        array<int, 26> map = {};
        int n = s1.size();

        for (int i = 0; i < 2; ++i) {
            for (int j = i; j < n; j += 2) {
                char c1 = s1[j];
                char c2 = s2[j];

                map[c1 - 'a'] += 1;
                map[c2 - 'a'] -= 1;
            }

            for (int c : map) {
                if (c != 0)
                    return false;
            }
        }

        return true;
    }
};
