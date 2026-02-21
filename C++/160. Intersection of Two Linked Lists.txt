/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
    {
        ListNode* current1 = head1; 
        ListNode* current2 = head2; 

        // If one of the head is NULL 
        if (!current1 or !current2) 
            return nullptr; 

        // Continue until we find intersection node 
        while (current1 and current2 and current1 != current2)
        { 
            current1 = current1->next; 
            current2 = current2->next; 

            // If we get intersection node 
            if (current1 == current2) 
                return current1; 

            // If one of them reaches end 
            if (!current1) 
                current1 = head2; 
            if (!current2) 
                current2 = head1; 
        } 

        return current1; 
    }
};