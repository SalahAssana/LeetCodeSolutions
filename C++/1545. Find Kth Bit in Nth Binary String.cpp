class Solution {
public:
    char findKthBit(int n, int k) {
        string result = "0";
        for(int i = 0; i < n; ++i) {
            result = result + "1" + reverse_invert(result);
        }

        return result[k-1];
    }

    string reverse_invert(string& n) {
        string result;
        for(char c : n) {
            result += c == '0' ? '1' : '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
