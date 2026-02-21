class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> result;
        int index = 0;
        
        // First, put all intervals that are to the left of the inserted interval.
        while (index < intervals.size() && intervals[index][1] < newInterval[0])
        {
            result.push_back(intervals[index++]);
        }
        
        // Second, merge all intervals that intersect with the inserted interval.
        while (index < intervals.size() && intervals[index][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        result.push_back(newInterval);
        
        // Finally, put all intervals that are to the right of the inserted interval.
        while (index < intervals.size())
        {
            result.push_back(intervals[index++]);
        }
        
        return result;
    }
};