class Solution {
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        string result;
        int cols = encodedText.size() / rows;

        if (cols == 0)
            return result;
        if (rows == 1)
            return encodedText;

        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                if (i + j == cols)
                    break;
                result += encodedText[i + j + j * cols];
            }
        }

        while (result.back() == ' ')
            result.pop_back();

        return result;
    }
};
