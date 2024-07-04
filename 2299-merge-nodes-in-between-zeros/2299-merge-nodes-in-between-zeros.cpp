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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* zero = head;
        ListNode* p = head->next;
        
        while(p!=NULL)
        {
            if(p->val != 0)
            {
                zero->val += p->val;
            }
            // consecutive zero
            else
            {
                // if it is last element
                if(p->next == NULL)
                {
                    zero->next = NULL;
                    break;
                }
                else
                {
                    zero->next = p;
                }
                // whatever the value of p it is null or something else just take it
                zero = p;
            }
            p = p->next;
        }
        return head;
    }
};