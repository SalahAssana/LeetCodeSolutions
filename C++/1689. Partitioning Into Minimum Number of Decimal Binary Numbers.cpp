class Solution {
public:
    int minPartitions(string n) {
        int result = 0;
        for(char c : n) {
            int digit = c-'0';
            if (digit > result) result = digit;
        }
        return result;
    }
};
