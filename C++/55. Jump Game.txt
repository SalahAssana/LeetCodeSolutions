class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return true;
        }
        
        int last_reachable_index = 0;
        
        for (int i = 0; i <= last_reachable_index; i++)
        {
            if (i + nums[i] > last_reachable_index)
            {
                if ((i+nums[i]) >= (nums.size()-1))
                {
                    return true;
                }
                else
                {
                    last_reachable_index = i + nums[i];
                }
            }
        }
        
        return false;
    }
};