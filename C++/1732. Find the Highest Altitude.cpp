class Solution {
public:
    int largestAltitude(vector<int>& gain)
    {
        int max_height = 0;
        int n = gain.size();

        int height = 0;
        for (int i = 0; i < n; ++i) {
            height += gain[i];
            max_height = max(max_height, height);
        }

        return max_height;
    }
};
