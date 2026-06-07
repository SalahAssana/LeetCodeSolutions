class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)
    {
        int n = A.size();
        vector<int> freq(n, 0);
        vector<int> result(n, 0);

        for (int i = 0; i < n; ++i) {
            int a = A[i], b = B[i];
            freq[a - 1] += 1;
            freq[b - 1] += 1;

            int r = (i > 0) ? result[i - 1] : 0;

            if (a == b)
                r += 1;
            else {
                r += ((freq[a - 1] & 1) == 0) * (freq[a - 1] != 0);
                r += ((freq[b - 1] & 1) == 0) * (freq[b - 1] != 0);
            }

            result[i] = r;
        }

        return result;
    }
};
