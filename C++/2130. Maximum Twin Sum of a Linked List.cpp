class Solution {
public:
    int pairSum(ListNode* head)
    {
        vector<int> nums;
        int result = 0;
        size_t idx = 0;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        idx = nums.size();
        for (size_t i = 0; i < idx / 2; ++i) {
            int sum = nums[i] + nums[idx - i - 1];
            result = max(result, sum);
        }

        return result;
    }
};
