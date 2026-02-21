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
    // To compare two points 
    class myComparator 
    { 
    public: 
        int operator() (const ListNode* p1, const ListNode* p2) 
        { 
            return p1->val > p2->val; 
        } 
    }; 

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // Priority queue to hold all the elements in sorted order
        priority_queue<ListNode*, vector<ListNode*>, myComparator> mypq;
        
        // Add the heads of all the lists to the priority queue
        for (ListNode* list : lists)
        {
            if (list != nullptr)
            {
                mypq.push(list);
            }
        }
        
        // Create dummy node as the head of the new linked list
        ListNode* head = new ListNode(-1);
        ListNode* iter = head;
        
        // Loop through the priority queue until it is emtpy and all nodes have been added
        while (!mypq.empty())
        {
            // Add node from priority queue to linked list
            iter->next = mypq.top(); mypq.pop();
            // Move iterator over
            iter = iter->next;
            
            // Get next node in linked list and add it to the priority queue
            ListNode* next = iter->next;
            if (next != nullptr)
            {
                mypq.push(next);
            }
        }
        
        return head->next;
    }
};