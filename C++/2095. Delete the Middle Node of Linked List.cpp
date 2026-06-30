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
    ListNode* deleteMiddle(ListNode* head)
    {
        ListNode **mid = &head, *end = head;
        int n = 0;
        while (end != NULL) {
            n += 1;
            end = end->next;

            if (n == 2) {
                mid = &(*mid)->next;
                n = 0;
            }
        }

        (*mid) = (*mid)->next;
        return head;
    }
};
