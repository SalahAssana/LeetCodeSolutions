class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
    
private:
    int maxSubArray(vector<int>& nums, int l, int r) 
    {
        if (l > r)
        {
            return INT_MIN;
        }
        
        int mid = l + (r - l) / 2, maxLeft = 0, maxRight = 0;
        int lmax = maxSubArray(nums, l, mid - 1);
        int rmax = maxSubArray(nums, mid + 1, r);
        
        for (int i = mid - 1, sum = 0; i >= l; i--)
        {
            sum += nums[i];
            maxLeft = max(sum, maxLeft);
        }
        
        for (int i = mid + 1, sum = 0; i <= r; i++)
        {
            sum += nums[i];
            maxRight = max(sum, maxRight);
        }
        
        return max(max(lmax, rmax), maxLeft + maxRight + nums[mid]);
    }
};