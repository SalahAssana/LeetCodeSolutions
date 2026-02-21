class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> compliment_set;
        int compliment;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++)
        {
            compliment = target - nums[i];
            
            if (compliment_set.find(compliment) != compliment_set.end())
            {
                result.push_back(compliment_set.find(compliment)->second);
                result.push_back(i);
                return result;
            }
            
            compliment_set[nums[i]] = i;
        }
        
        return result;
    }
};