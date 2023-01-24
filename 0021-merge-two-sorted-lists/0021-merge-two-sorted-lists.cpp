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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* ans = new ListNode();
        ListNode* itr = ans;
        
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                itr->next = l1;
                itr = itr->next;
                l1 = l1->next;
            }
            else
            {
                itr->next = l2;
                itr = itr->next;
                l2 = l2->next;
            }
        }
        
        while(l1)
        {
            itr->next = l1;
            itr = itr->next;
            l1 = l1->next;
        }
        while(l2)
        {
            itr->next = l2;
            itr = itr->next;
            l2 = l2->next;
        }
        return ans->next;
    }
};