class Solution {
public:
    int numberOfSpecialChars(string word)
    {
        uint32_t low = 0, cap = 0, ign = 0;
        int n = word.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            char c = word[i];
            int o = c - 'a';
            if (o < 0) {
                o = c - 'A';
                cap |= (1 << o);
            } else {
                uint32_t bit = 1 << o;
                low |= bit;
                if (((cap & low) & bit) != 0)
                    ign |= bit;
            }
        }

        uint32_t special = (cap & low) & (~ign);
        cout << bitset<32>(cap) << "\n"
             << bitset<32>(low) << "\n"
             << bitset<32>(ign);
        for (int i = 0; i < 26; ++i) {
            result += ((1 << i) & special) != 0;
        }

        return result;
    }
};
