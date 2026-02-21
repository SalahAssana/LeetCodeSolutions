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
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        // Maintain two nodes: current and previous
        // If they are different move both
        // If they are the same delete current node and don't move previous
        
        ListNode* aux_head = new ListNode(-1);
        ListNode* aux_head_iter = aux_head;
        
        while (head)
        {
            if (head->next && head->val == head->next->val)
            {
                int currentValue = head->val;
                
                while(head && head->val == currentValue)
                {
                    head = head->next;
                }
            }
            else
            {
                aux_head_iter->next = head;
                aux_head_iter = aux_head_iter->next;
                head = head->next;
            }
        }
        
        aux_head_iter->next = nullptr;
        
        return aux_head->next;
    }
};