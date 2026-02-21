class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int row = 0;
        array<int, 9> column = {};
        array<int, 9> box = {};
        
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.') continue;
                
                int n = board[i][j] - 49;
                
                if (row & (1 << n)) return false;
                row |= (1 << n);
                
                if (column[j] & (1 << n)) return false;
                column[j] |= (1 << n);
                
                int b = j / 3 + (i / 3) * 3;
                if (box[b] & (1 << n)) return false;
                box[b] |= (1 << n);
            }
            row = 0;
        }
        
        return true;
    }
};