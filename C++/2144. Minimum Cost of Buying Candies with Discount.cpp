class Solution {
public:
    int minimumCost(vector<int>& cost)
    {
        int n = cost.size();
        int total_cost = accumulate(cost.begin(), cost.end(), 0);

        sort(cost.begin(), cost.end(), greater<int>());

        for (int i = 0; i < n - 2; i += 1) {
            int max_limit = min(cost[i], cost[i + 1]);
            int candy_cost = cost[i + 2];

            if (candy_cost <= max_limit) {
                total_cost -= candy_cost;
                i += 2;
            }
        }

        return total_cost;
    }
};
