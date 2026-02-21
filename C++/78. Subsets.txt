class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        // vector to return
        vector<vector<int>> output;
        // size of input array
        int n = nums.size();
        
        // always start with empty array
        output.push_back({});
        
        // loop through every value in input vector
        for(int i = 0; i < n; i++)
        {
            // current size of output array
            // i.e. number of subsets
            int sz = output.size();
            
            // loop through all existing subsets
            for(int j = 0; j < sz; j++)
            {
                // start with existing sets
                vector<int> temp = output[j];
                // add new value to existing subset
                temp.push_back(nums[i]);
                // add the new subset to output
                output.push_back(temp);
            }
            
        }
        
        // return set all of permuations
        return output;
    }
};