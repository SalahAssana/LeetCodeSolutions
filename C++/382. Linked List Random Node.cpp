class Solution {
public:
    Solution(ListNode* head)
    {
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom()
    {
        int n = nums.size();
        return nums[rand() % n];
    }

    vector<int> nums;
};
