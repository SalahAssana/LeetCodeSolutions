class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size();
        int mid;
        int left;
        int right;
        
        while (start < end)
        {
            mid = start + (end - start) / 2;
            
            if (nums[mid] >= target)
                end = mid;
            else
                start = mid + 1;
        }
        
        left = start;
        start = 0, end = nums.size();
        
        while (start < end)
        {
            mid = start + (end - start) / 2;
            
            if (nums[mid] > target)
                end = mid;
            else
                start = mid + 1;
        }
        
        right = start;
        
        return left == right ? vector<int> {-1,-1} : vector<int> {left,right-1};
    }
};