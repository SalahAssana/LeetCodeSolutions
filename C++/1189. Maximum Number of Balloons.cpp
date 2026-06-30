class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for (auto c : text) {
            switch (c) {
            case 'b':
                b++;
                break;
            case 'a':
                a++;
                break;
            case 'l':
                l++;
                break;
            case 'o':
                o++;
                break;
            case 'n':
                n++;
                break;
            }
        }

        int count = min(b, a);
        count = min(count, l / 2);
        count = min(count, o / 2);
        count = min(count, n);
        return count;
    }
};
