class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            
            if (nums[mid] == target)
            {
                return mid;
            }
            // If left handed side is sorted
            else if (nums[left] <= nums[mid])
            {
                // If the value is on the left side
                if (target <= nums[mid] && target >= nums[left])
                {
                    right = mid - 1;
                }
                // If the value is on the right side
                else
                {
                    left = mid + 1;
                }
            }
            // If right handed side is sorted
            else
            {
                // If the value is on the right side
                if (target >= nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                // If value is on the left side
                else
                {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};