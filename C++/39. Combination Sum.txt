class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        
        sort(candidates.begin(), candidates.end());
        vector<int> pSol;
        search(candidates, 0, pSol, target, result);
        
        return result; 
    }
    
private:
    void search(vector<int>& candidates, int index, vector<int>& pSol, int target, vector<vector<int>>& result)
    {
        // If we found a sum that leads to the target add it
        if(target == 0)
        {
            result.push_back(pSol);
            return;
        }
        
        // If we reach the end of the candidated array or become negative a solution isn't possible
        if(index == candidates.size() || target - candidates[index] < 0)
            return;
        
        // Add new candidate value to possible solution
        pSol.push_back(candidates[index]);
        // Check possible solutions with the same candidate
        search(candidates, index, pSol, target - candidates[index], result);
        // Remove candidate from possible solution
        pSol.pop_back();
        // Check with next possible candidate
        search(candidates, index + 1, pSol, target, result);
    }
};