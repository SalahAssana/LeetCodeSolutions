class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        string result;
        unordered_map<string, string> k;

        for (auto& p : knowledge) {
            k[p[0]] = p[1];
        }
        
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c != '(') {
                result += c;
            } else {
                int j = i+1;
                while(s[++j] != ')');
                const string key(s.begin()+i+1, s.begin()+j);
                string val = k[key];
                result += val == "" ? "?" : val;
                i=j;
            }
        }

        return result;
    }
};
