class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int> (n, 1));
        
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        
        int index = 0;
        
        while (left <= right && top <= bottom)
        {
            for (unsigned int j = left; j <= right; j++)
                res[top][j] = ++index;
            top++;
            
            for (unsigned int i = top; i <= bottom; i++)
                res[i][right] = ++index;
            right--;
            
            for (int j = right; j >= left; j--)
                res[bottom][j] = ++index;
            bottom--;
            
            for (int i = bottom; i >= top; i--)
                res[i][left] = ++index;
            left++;
        }
        
        return res;
    }
};