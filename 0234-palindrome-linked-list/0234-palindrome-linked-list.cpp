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
    bool isPalindrome(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return true;
        if(head->next->next == nullptr) return head->val == head->next->val;

         ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = head;
        //reverse a second half of linked list 
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while(curr!=nullptr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        cout << prev->val << " slow " << slow->val <<endl;
        slow = prev;


        while(slow){
            cout << "fast val " << fast->val << " slow val " << slow->val << endl;
            if(fast->val != slow->val){
                cout << "not a palindrome" << endl;
                return false;
            }
            slow= slow->next;
            fast = fast->next;
        }
        return true;
    }
};