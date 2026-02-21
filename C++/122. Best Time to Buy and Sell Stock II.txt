class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int maxprofit = 0;
        int valley = prices[0];
        int peak = prices[0];
        
        for (int i = 0; i < n-1; i++)
        {
            while (i < n-1 and prices[i] >= prices[i+1])
            {
                i++;
            }
            
            valley = prices[i];
            
            while (i < n-1 and prices[i] <= prices[i+1])
            {
                i++;
            }
            
            peak = prices[i];
            
            maxprofit += peak - valley;
        }
        
        return maxprofit;
    }
};