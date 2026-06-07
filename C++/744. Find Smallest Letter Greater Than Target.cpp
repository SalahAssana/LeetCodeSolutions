class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        int result = 0;
        int n = letters.size();

        for (int i = 0; i < n; ++i) {
            if (letters[i] > target) {
                result = i;
                break;
            }
        }

        return letters[result];
    }
};
