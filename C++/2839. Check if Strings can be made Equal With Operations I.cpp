class Solution {
public:
    bool canBeEqual(string s1, string s2)
    {
        unordered_set<string> m1, m2;

        string n1 = s1, n2 = s2;
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < 2; ++i) {
                swap(n1[i], n1[i + 2]);
                swap(n2[i], n2[i + 2]);

                m1.insert(n1);
                m2.insert(n2);
            }
        }

        vector<string> result;
        set_intersection(m1.begin(), m1.end(), m2.begin(), m2.end(), back_inserter(result));

        return result.size() != 0;
    }

    void swap(char& c1, char& c2)
    {
        char temp = c1;
        c1 = c2;
        c2 = temp;
    }
};
