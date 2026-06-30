class Solution {
public:
    string processStr(string s)
    {
        char result[999999] = { };
        int len = 0;

        for (auto& c : s) {
            if (c >= 'a' && c <= 'z') {
                result[len++] = c;
            } else if (c == '*') {
                if (len) {
                    result[--len] = 0;
                }
            } else if (c == '#') {
                for (int i = 0; i < len; ++i) {
                    result[i + len] = result[i];
                }
                len *= 2;
            } else if (c == '%') {
                for (int i = 0; i < len / 2; ++i) {
                    char temp = result[i];
                    result[i] = result[len - i - 1];
                    result[len - i - 1] = temp;
                }
            }
        }

        return string(result, result + len);
    }
};
