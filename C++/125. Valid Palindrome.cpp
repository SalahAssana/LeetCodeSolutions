class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string result;
        result.reserve(n);

        for (auto c : s)
        {
            if (c >= 'A' && c <= 'Z') c -= 'A'-'a';
            else if (c >= 'a' && c <= 'z');
            else if (c >= '0' && c <= '9');
            else continue;

            result += c;
        }

        n = result.size();
        for (int i = 0; i < n/2; ++i)
        {
            if (result[i] != result[n-i-1]) return false;
        }

        return true;
    }
};
