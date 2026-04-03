class Solution {
public:
    int minOperations(string s) {
        int result = 0;
        int p = 0;
        int len = s.size();
        for (char c : s) {
            int d = c - '0';
            result += d == p;
            p = p == 0;
        }

        return min(result, len-result);
    }
};
