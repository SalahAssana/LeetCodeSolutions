class Solution
{
private:
    void permutate(vector<int>& nums, vector<vector<int>>& results, int n)
    {
        if (n == nums.size()-1)
        {
            results.push_back(nums);
        }
        else
        {
            for(int i = n; i < nums.size(); i++)
            {
                swap(nums[i], nums[n]);
                permutate(nums, results, n + 1);
                swap(nums[i], nums[n]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> results;
        permutate(nums, results, 0);
        return results;
    }
};