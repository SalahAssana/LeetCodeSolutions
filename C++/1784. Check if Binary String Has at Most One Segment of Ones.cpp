class Solution {
public:
    bool checkOnesSegment(string s)
    {
        int found = 0;
        int seg = 0;
        for (auto c : s) {
            found |= c == '1';
            seg += found && (c == '0');
            found = !(c == '0');
        }

        seg += found;

        return seg <= 1;
    }
};
