class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        
        if (n == 0) return 0;
        
        vector<int> dp(n, 1);
        
        int maxLIS = 1;
        int currentLIS = 0;
        
        for (int i = 1; i < n; i++)
        {
            currentLIS = 0;
            
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && dp[j] > currentLIS)
                {
                    currentLIS = dp[j];
                }
            }
            
            dp[i] = currentLIS + 1;
            
            maxLIS = max(maxLIS, dp[i]);
        }
        
        return maxLIS;
    }
};