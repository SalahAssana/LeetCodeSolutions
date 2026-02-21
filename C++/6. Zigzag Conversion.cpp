class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) return s;
        
        vector<string> rows(min(numRows, int(s.size())));
        int currentRow = 0;
        bool changeDirection = false;
        
        for (char c : s)
        {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) changeDirection = !changeDirection;
            currentRow += changeDirection ? 1 : -1;
        }
        
        string zigzag;
        
        for (string s : rows)
        {
            zigzag += s;
        }
        
        return zigzag;
    }
};