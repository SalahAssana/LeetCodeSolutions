class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //divide the list into two parts 
        fast = slow->next;
        slow->next = nullptr;
        
        return merge(sortList(head), sortList(fast));
    }
    
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode dump(0);
        ListNode* cur = &dump;
        
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }
                
            cur = cur->next;
        }
        
        if (left != nullptr)
            cur->next = left;
        else
            cur->next = right;
            
        return dump.next;
    }
};