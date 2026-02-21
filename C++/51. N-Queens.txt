class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        unordered_set<int> column;
        unordered_set<int> diagonal1;
        unordered_set<int> diagonal2;
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solveNQueens(board, 0, column, diagonal1, diagonal2, result, n);
        return result;
    }
    
private:
    void solveNQueens(vector<string> &board,
                      int row,
                      unordered_set<int> &column,
                      unordered_set<int> &diagonal1,
                      unordered_set<int> &diagonal2,
                      vector<vector<string>> &result,
                      int queensLeft)
    {
        if (row == board.size())
        {
            if (queensLeft == 0)
            {
                result.push_back(board);
            }
            return;
        }
        
        for (int col = 0; col < board.size(); col++)
        {
            if (column.count(col) == 0 &&
                diagonal1.count(row+col) == 0 &&
                diagonal2.count(col-row) == 0)
            {
                board[row][col] = 'Q';
                column.insert(col);
                diagonal1.insert(row+col);
                diagonal2.insert(col-row);
                solveNQueens(board, row+1, column, diagonal1, diagonal2, result, queensLeft-1);
                board[row][col] = '.';
                column.erase(col);
                diagonal1.erase(row+col);
                diagonal2.erase(col-row);
            }
        }
        
        return;
    }
};