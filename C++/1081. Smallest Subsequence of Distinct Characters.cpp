class Solution {
public:
    string smallestSubsequence(string s)
    {
        vector<int> count(26, 0), pres(26, 0);
        int n = s.size();
        for (auto c : s)
            count[c - 'a'] += 1;

        string res;
        for (char c : s) {
            if (!pres[c - 'a']) {
                while (res.size() && res.back() > c) {
                    if (count[res.back() - 'a'] > 0) {
                        pres[res.back() - 'a'] = 0;
                        res.pop_back();
                    } else {
                        break;
                    }
                }

                res.push_back(c);
                pres[c - 'a'] = 1;
            }
            count[c - 'a'] -= 1;
        }

        return res;
    }
};
