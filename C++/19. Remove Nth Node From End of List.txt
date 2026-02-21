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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // Pre processing
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return nullptr;
        
        ListNode *first = head;
        ListNode *second = head;
        
        // Advance first pointed by a distance of n
        for (int i = 0; i < n; i++)
        {
            first = first->next;
        }
        
        // This will only occure when the element we want to remove is the head
        if(first == nullptr)
        {
            head = head->next;
            return head;
        }
        
        // Move first until end of list while moving second at the same time
        // When first reaches end of the list slow will be at size - n
        while (first->next != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        
        return head;
    }
};