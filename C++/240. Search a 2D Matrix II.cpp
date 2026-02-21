class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int row = matrix.size();
        
        if (row == 0)
            return false;
        
        int col = matrix[0].size();
        
        if (col == 0)
            return false;
        
        if (target < matrix[0][0] || target > matrix[row-1][col-1])
            return false;
        
        int i = 0, j = col - 1;
        
        while (i < row && j >=0)
        {
            if (target == matrix[i][j])
                return true;
            //if target > matrix[i][j],then target must not appear in row-i
            else if (target > matrix[i][j])
                ++i;
            //if target < matrix[i][j],then target must not appear in column-j
            else
                --j;
        }
        
        return false;
    }
};