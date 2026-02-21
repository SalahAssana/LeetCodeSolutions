class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() < 3)
            return nums.size();
        
        int n = nums.size(), left = 2;
        
        for (int right = 2; right < n; right++)
        {
            if (nums[left-2] != nums[right])
                nums[left++] = nums[right];
        }

        return left;
    }
};