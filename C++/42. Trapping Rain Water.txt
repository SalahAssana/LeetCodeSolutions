class Solution
{
public:
    int trap(vector<int>& height)
    {
        if(height.size() == 0)
		    return 0;
        
        int n = height.size();
        
        vector<int> maxHeightsLeft(n);
        maxHeightsLeft[0] = height[0];
        
        for (int i = 1; i < n; i++)
        {
            maxHeightsLeft[i] = max(height[i], maxHeightsLeft[i-1]);
        }
        
        vector<int> maxHeightsRight(n);
        maxHeightsRight[n-1] = height[n-1];
        
        for (int i = n-2; i >= 0; i--)
        {
            maxHeightsRight[i] = max(height[i], maxHeightsRight[i+1]);
        }
        
        int maxWater = 0;
        
        for (int i = 1; i < n-1; i++)
        {
            maxWater += min(maxHeightsLeft[i], maxHeightsRight[i]) - height[i];
        }
        
        return maxWater;
    }
};