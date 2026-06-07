class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        int sum_cap = 0;
        int min_count = accumulate(apple.begin(), apple.end(), 0);

        sort(capacity.begin(), capacity.end());
        int i = capacity.size() - 1;
        while (sum_cap < min_count)
            sum_cap += capacity[i--];

        return capacity.size() - i - 1;
    }
};
