class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> pSol;
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, result, pSol, 0, target);
        return result;
    }
    
private:
    void combinationSum2(vector<int>& candidates, vector<vector<int>> &result, vector<int> pSol, int index, int target)
    {
        if (target == 0)
        {
            result.push_back(pSol);
            return;
        }
        
        if (target < 0)
        {
            return;
        }
        
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i-1])
                continue;
            
            pSol.push_back(candidates[i]);
            combinationSum2(candidates, result, pSol, i + 1, target - candidates[i]);
            pSol.pop_back();
            
        }
        
        return;
    }
};