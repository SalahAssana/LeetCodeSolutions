class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> elementCount;
        int majoritySize = nums.size() / 2;
        
        for (int num : nums)
        {
            if (++elementCount[num] > majoritySize)
                return num;
        }
        
        return 0;
    }
};