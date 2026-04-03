class Solution {
public:
    string generateTag(string caption)
    {
        string result = "#";
        bool space = false;
        int m = caption.size();
        int i = 0;
        for (i = 0; i < m && caption[i] == ' '; ++i)
            ;
        for (; i < m; ++i) {
            char c = caption[i];

            if (result.size() == 100)
                break;
            if (isalpha(c)) {
                if (space == true) {
                    c = toupper(c);
                    space = false;
                } else
                    c = tolower(c);
                result += c;
            } else if (c == ' ') {
                space = true;
            }
        }

        return result;
    }
};
