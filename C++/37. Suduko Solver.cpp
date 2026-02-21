class Solution
{
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        solveSudoku(board, 0, 0);
    }
    
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        // row check
        for(int i = 0; i < 9; i++) 
            if(board[i][col] == c) 
                return false;
        
        // col check
        for(int i = 0; i < 9; i++) 
            if(board[row][i] == c) 
                return false;
        
        // box check
        int x0 = (row/3) * 3, y0 = (col/3) * 3;
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[x0 + i][y0 + j] == c) return false;
            }
        }
        
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board, int row, int column)
    {
        if (row == 9)
            return true;
        
        if (column == 9)
            return solveSudoku(board, row + 1, 0);
        
        if (board[row][column] != '.')
            return solveSudoku(board, row, column + 1);
        
        for (char c = '1'; c <= '9'; c++)
        {
            if (isValid(board, row, column, c))
            {
                board[row][column] = c;
                
                if(solveSudoku(board, row, column + 1))
				    return true;

                board[row][column] = '.';
            }
        }
        
        return false;
    }
};