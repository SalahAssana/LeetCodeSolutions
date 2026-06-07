class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex)
    {
        int n = words.size();
        int offset;
        int result = -1;
        for (offset = 0; offset < n; ++offset) {
            if (words[(offset + startIndex) % n] == target) {
                if (result == -1)
                    result = 101;
                result = min(result, min(offset, n - offset));
            }
        }

        return result;
    }
};
