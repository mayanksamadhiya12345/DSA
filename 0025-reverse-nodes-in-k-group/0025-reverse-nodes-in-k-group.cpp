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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = new ListNode();
        ans->next = head;

        ListNode* pre = ans;
        ListNode* curr = ans;
        ListNode* next = ans;

        int count=0;
        while(curr->next) {
            count++;
            curr=curr->next;
        }

        while(count>=k) {
            curr = pre->next;
            next = curr->next;

            for(int i=1;i<k;i++) {
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = curr->next;
            }

            count -= k;
            pre = curr;
        }
        return ans->next;
    }
};