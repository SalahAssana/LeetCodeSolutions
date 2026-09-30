class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<uint64_t> dp(n, 0);
        const int mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            uint64_t p = (i > 0 ? dp[i-1] : 1) % mod;

            int ways = (s[i] != '0') + (s[i]=='*')*8;
            dp[i] = (dp[i] + (p * ways));

            if (i+1 < n) {
                if (s[i] == '*' && s[i+1] == '*') ways = 9 + 6;
                else if (s[i] == '*') {
                    int sum = 10 + (s[i+1]-'0');
                    ways = (sum >= 10 && sum <= 26);
                    sum += 10;
                    ways += (sum >= 10 && sum <= 26);
                }
                else if (s[i+1] == '*') ways = (s[i]=='1')*9 + (s[i]=='2')*6;
                else {
                    int sum = (s[i]-'0')*10 + (s[i+1]-'0');
                    ways = (sum >= 10 && sum <= 26);
                }
                dp[i+1] = (dp[i+1] + (p * ways));
            }
        }

        return dp[n-1] % mod;
    }
};
