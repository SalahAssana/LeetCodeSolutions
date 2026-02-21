class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int minprice = INT_MAX;
        int maxprofit = 0;
        
        for (int i = 0; i < prices.size(); i++)
        {
            // Find minimum price so far
            if (prices[i] < minprice)
                minprice = prices[i];
            // Find max difference since the last minimum found
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        
        return maxprofit;
    }
};