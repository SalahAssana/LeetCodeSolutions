class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int maxRectangle = 0;
        
        stack<int> indexStack;
        
        // For cases were we only have one item
        heights.push_back(0);
        
        for (int i = 0; i < heights.size(); i++)
        {
            while(!indexStack.empty() && heights[indexStack.top()] > heights[i])
            {
                int maxHeight = heights[indexStack.top()]; indexStack.pop();
                int leftBound = indexStack.empty() ? -1 : indexStack.top();
                int rightBound = i;
                maxRectangle = max(maxRectangle, maxHeight*(rightBound-leftBound-1));
            }
            
            indexStack.push(i);
        }
        
        return maxRectangle;
    }
};