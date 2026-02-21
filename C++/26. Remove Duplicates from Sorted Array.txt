class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int duplicateCount = 0;
        int i = 0;
        int j = 1;
        
        while (j < (int)nums.size())
        {
            if (nums[i] == nums[j])
            {
                duplicateCount++;
                j++;
            }
            else
            {
                nums[++i] = nums[j++];
            }
        }
        
        return ((int)nums.size() - duplicateCount);
    }
};