class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        
        slow = nums[slow];
        fast = nums[nums[fast]];
        
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        int a = nums[0];
        int b = slow;
        
        while (a != b)
        {
            a = nums[a];
            b = nums[b];
        }
        
        return a;
    }
};