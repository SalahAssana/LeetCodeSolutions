/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* result = nullptr;
        ListNode* rev = nullptr;
        ListNode* left_tail = nullptr;
        ListNode** pright_start = nullptr;
        ListNode* rev_last = nullptr;

        int i = 0;
        ListNode* cur = head;
        while(cur != nullptr && ++i) {

            if (i >= left && i <= right) {
                ListNode* temp = cur->next;
                cur->next = rev;
                rev = cur;
                if (rev_last == nullptr) rev_last = cur;
                cur = temp;
                continue;
            } else if (i == left-1) {
                left_tail = cur;
            } else if (i > right) break;

            cur = cur->next;
        }

        if (left == 1) result = rev;
        if (left != 1) {
            left_tail->next = rev;
            result = head;
        }

        rev_last->next = cur;

        return result;
    }
};
