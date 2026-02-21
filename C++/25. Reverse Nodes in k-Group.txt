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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* root = new ListNode(0, head);
        ListNode* curr = head;
        ListNode* prev = root;
        
        int listIndex;
        
        while (curr != nullptr)
        {
            ListNode* tail = curr;
            listIndex = 0;
            
            while (curr != nullptr && listIndex < k)
            {
                curr = curr->next;
                listIndex++;
            }
            
            if (listIndex != k)
            {
                prev->next = tail;
            }
            else
            {
                prev->next = reverse(tail, k);
                prev = tail;
            }
        }
        
        return root->next;
    }
    
private:
    ListNode* reverse(ListNode* head, int k)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        while (curr != nullptr && k-- > 0)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        return head;
    }
};