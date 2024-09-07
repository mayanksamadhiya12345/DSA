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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());

        for(auto&it : st) cout<<it<<" ";

        ListNode* newHead = new ListNode();
        ListNode* itr = newHead;
        cout<<endl;
        while(head)
        {
            if(st.find(head->val) == st.end())
            {
                cout<<head->val<<" ";
                itr->next = new ListNode(head->val);
                itr = itr->next;
            }

            head = head->next;
        }
        // itr->next = NULL;
        return newHead->next;
    }
};