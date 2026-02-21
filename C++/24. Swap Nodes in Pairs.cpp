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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* curr = head;
        ListNode* root = prev;
        
        while (prev->next != nullptr && curr->next != nullptr)
        {
            prev->next = curr->next; 
            curr->next = curr->next->next;
            prev->next->next = curr;
            prev = curr; 
            curr = curr->next;
        }
        
        return root->next;
    }
};