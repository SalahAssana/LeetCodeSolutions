class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int n = intervals.size();
        int result = n;
        for (int i = 0; i < n; ++i) {
            int idx = i - 1;
            while (idx >= 0 && !is_surrounding(intervals[idx], intervals[i]))
                idx--;
            result -= idx != -1;
        }

        return result;
    }

    bool is_surrounding(const vector<int>& a, const vector<int>& b)
    {
        return a[0] <= b[0] && a[1] >= b[1];
    }
};
