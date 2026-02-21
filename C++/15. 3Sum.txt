class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // Vector for outpu
        vector<vector<int>> solution;
        
        if(nums.size()<3) return solution;
        
        // Sort for two sum solution
        sort(nums.begin(),nums.end());
        
        // Loop through the whole array
        for(int i=0;i<nums.size()-2;i++)
        {
            // If we have a duplicate we through it away
            if(i > 0 and nums[i] == nums[i-1]) continue;
            
            // Now we just use the regular two sum solution
            int start = i+1;
            int stop = nums.size()-1;
            
            while(start < stop)
            {
                // If match found add it to array
                if(nums[start] + nums[stop] == -nums[i])
                {
                    solution.push_back({nums[start++],nums[stop--],nums[i]});
                    // Skip over duplicates
                    while(start<stop && nums[start]==nums[start-1]) start++;
                    while(stop>start && nums[stop]==nums[stop+1]) stop--;

                }
                else if(nums[start] + nums[stop] < -nums[i])
                {
                    start++;
                }
                else
                {
                    stop--;
                }

            }   
        }
        
        return solution;
    }
};