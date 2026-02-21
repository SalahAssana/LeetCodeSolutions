class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        
        while (low <= high)
        {
            while (low < high && nums[low] == nums[low + 1]) low++; // skip duplicates from the left
            while (high > low && nums[high] == nums[high - 1]) high--; // skip duplicates from the right
            
            mid = low + (high - low) / 2;
            
            if (nums[mid] == target)
            {
                return true;
            }
            
            // We are on the left side of the pivot
            if (nums[mid] > nums[high])
            {
                if (target < nums[mid] && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // We are on the right side of the pivot
            else if (nums[mid] < nums[low])
            {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            // Normal binary search
            else
            {
                if (target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        
        return false;
    }
};