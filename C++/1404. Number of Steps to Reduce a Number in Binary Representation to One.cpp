class Solution {
public:
    int numSteps(string s)
    {
        int n = s.size();
        int r = n - 1;
        int steps = 0;

        while (r >= 1) {
            if (s[r] == '0') {
                r--;
            } else {
                int i = r;
                while (i >= 0) {
                    if (s[i] == '1')
                        s[i] = '0';
                    else
                        break;
                    i -= 1;
                }
                if (i >= 0)
                    s[i] = '1';
                else {
                    s = "1" + s;
                    r += 1;
                }
            }

            steps += 1;
        }

        return steps;
    }
};
