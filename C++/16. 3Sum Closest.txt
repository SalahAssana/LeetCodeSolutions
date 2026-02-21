class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int diff = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        if (nums.size() <= 3)
        {
            return nums[0] + nums[1] + nums[2];
        }
        
        for (int i = 0; i < nums.size()-2; i++)
        {
            int low = i+1;
            int high = nums.size()-1;
            int sum = 0;
            
            while (low < high)
            {
                sum = nums[i] + nums[low] + nums[high];
                
                if (abs(target - sum) < abs(diff))
                {
                    diff = target - sum;
                }
                
                if (diff == 0)
                {
                    break;
                }
                
                if (sum < target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        
        return target - diff;
    }
};