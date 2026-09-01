
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        vector<int> critical_points;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        int idx = 0;
        int min_dist = 1e5;

        while (cur) {
            if (prev != nullptr && cur->next != nullptr) {

                if ((prev->val < cur->val && cur->val > cur->next->val) || (prev->val > cur->val && cur->val < cur->next->val)) {
                    critical_points.push_back(idx);
                }

                if (critical_points.size() >= 2) {
                    int n = critical_points.size() - 1;
                    min_dist = min(min_dist,
                        critical_points[n] - critical_points[n - 1]);
                }
            }

            idx += 1;
            prev = cur;
            cur = cur->next;
        }

        if (critical_points.size() < 2)
            return { -1, -1 };

        int max_dist = critical_points.back() - critical_points.front();

        return { min_dist, max_dist };
    }
};
