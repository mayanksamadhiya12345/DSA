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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans = new ListNode();
        ans->next = head;
        ListNode* slow = ans;
        ListNode* fast = ans;
        
        for(int i=1; i<=n; i++){
            fast = fast->next;
        }

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
       
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        
        return ans->next;
    }
};