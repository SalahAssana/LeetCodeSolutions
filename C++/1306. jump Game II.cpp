class Solution {
public:
    bool canReach(vector<int>& arr, int start)
    {
        int n = arr.size();
        int dir = 0;
        int zero_count = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                dir = (i > start) - (i < start);
                zero_count += 1;
            }
        }

        int sum = accumulate(arr.begin(), arr.end(), zero_count);
        if (sum == n)
            return true;

        queue<pair<int, int>> q;
        q.push(make_pair(start, n));
        while (q.size()) {
            auto p = q.front();
            q.pop();

            int i = p.first, l = p.second;
            if (p.second == 0)
                continue;

            int dist = arr[i];
            if (dist == 0)
                return true;
            pair<int, int> left = make_pair((i - dist), l - 1), right = make_pair((i + dist), l - 1);

            if (dir == -1) {
                if (left.first >= 0)
                    q.push(left);
                if (right.first < n)
                    q.push(right);
            } else {
                if (right.first < n)
                    q.push(right);
                if (left.first >= 0)
                    q.push(left);
            }
        }

        return false;
    }
};
