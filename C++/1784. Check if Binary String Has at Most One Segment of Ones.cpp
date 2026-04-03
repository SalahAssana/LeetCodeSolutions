class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        int n = s.size();

        while(s[i] == '1' && i < n) i+=1;
        while(s[i] == '0'&& i < n) i+=1;

        return i == n;
    }
};
