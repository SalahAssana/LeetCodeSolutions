class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        if(nums.empty())
        {
            return 0;
        }
        
        int currentMax = nums[0];
        int currentMin = nums[0];
        int currentMaxProduct = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            int p1 = currentMax * nums[i];
            int p2 = currentMin * nums[i];
            
            currentMax = max(nums[i], max(p1, p2));
            currentMin = min(nums[i], min(p1, p2));
            
            currentMaxProduct = currentMax > currentMaxProduct ? currentMax : currentMaxProduct;
        }
        
        return currentMaxProduct;
    }
};