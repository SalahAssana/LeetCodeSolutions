class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        vector<bool> found(1 << k, false);
        int n = s.size();
        size_t found_count = 0;

        for (int i = 0; i <= n - k; ++i) {
            uint32_t bits = make_bits(s.c_str() + i, k);
            found_count += (found[bits] == false);
            found[bits] = true;
        }

        return found_count == found.size();
    }

    uint32_t make_bits(const char* start, int size)
    {
        uint32_t result = 0;
        for (int i = 0; i < size; ++i) {
            result = (result << 1);
            result |= (*(start + i) == '1');
        }

        return result;
    }
};
