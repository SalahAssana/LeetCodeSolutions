class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.size() == 0) return 0;
        
        int islandCount = 0;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    islandCount++;
                    sinkIsland(grid, i, j);
                }
            }
        }
        
        return islandCount;
    }
    
    void sinkIsland(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        sinkIsland(grid, i+1, j);
        sinkIsland(grid, i-1, j);
        sinkIsland(grid, i, j+1);
        sinkIsland(grid, i, j-1);
        
        return;
    }
};