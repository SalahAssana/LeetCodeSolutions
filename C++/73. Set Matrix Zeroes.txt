class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        // If the matrix is empty we just return
        if(matrix.empty()) return;
        
        // Set variables for row and column size
        int rowSize = matrix.size(), colSize = matrix[0].size();
        
        // Keep flag in case first row or column has a zero (will use later)
        bool firstRow = false, firstCol = false;
        for(int c = 0; c < colSize; ++c) if(matrix[0][c] == 0) firstRow = true;
        for(int r = 0; r < rowSize; ++r) if(matrix[r][0] == 0) firstCol = true;
        
        // Loop through matrix and set flag for each 0 value
        for(int r = 1; r < rowSize; ++r)
            for(int c = 1; c < colSize; ++c)
                if(matrix[r][c] == 0) matrix[0][c] = matrix[r][0] = 0;
        
        // Loop through first column and set all needed columns to 0
        for(int c = 1; c < colSize; ++c) 
            if(matrix[0][c] == 0)
                for(int r = 1; r < rowSize; ++r)
                    matrix[r][c] = 0;
        
        // Loop through first row and set all needex rows to 0
        for(int r = 1; r < rowSize; ++r) 
            if(matrix[r][0] == 0)
                for(int c = 1; c < colSize; ++c)
                    matrix[r][c] = 0;
        
        // If the first row or column are 0 set them to 0
        if(firstRow) for(int c = 0; c < colSize; ++c) matrix[0][c] = 0;
        if(firstCol) for(int r = 0; r < rowSize; ++r) matrix[r][0] = 0;
    }
};