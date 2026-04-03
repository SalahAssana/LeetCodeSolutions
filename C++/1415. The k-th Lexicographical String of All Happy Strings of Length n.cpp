class Solution {
public:
    string getHappyString(int n, int k)
    {
        char dict[3] = { 'a', 'b', 'c' };
        int cnt = 0;
        string ans = "";
        auto dfs = [&](this auto&& dfs, int i, string& tmp) {
            if (i == n) {
                cnt += 1;
                if (cnt == k)
                    ans = tmp;
                return;
            }
            for (char c : dict) {
                if (cnt == k)
                    break;
                if (tmp.empty() || tmp.back() != c) {
                    tmp.push_back(c);
                    dfs(i + 1, tmp);
                    tmp.pop_back();
                }
            }
        };
        string tmp = "";
        dfs(0, tmp);
        return ans;
    }
};
