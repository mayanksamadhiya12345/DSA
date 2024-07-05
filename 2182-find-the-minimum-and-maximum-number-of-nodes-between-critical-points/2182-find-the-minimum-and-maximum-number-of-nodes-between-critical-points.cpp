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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==NULL || head->next->next==NULL) return {-1,-1};
        vector<int> ans(2);

        int prev = head->val; // 5
        int curr = 0;
        int next = 0;
        ListNode* itr = head->next;

        vector<int> critical;
        int idx = 2;

        int prev_idx = -1;
        int curr_idx = -1;

        while(itr->next)
        {
            curr = itr->val; //3
            next = itr->next->val; //1

            // Either it can be local minima
            if(curr<prev && curr<next) critical.push_back(idx);

            // or local maxima
            if(curr>prev && curr>next) critical.push_back(idx);

            prev = curr;
            itr = itr->next;
            idx++;
        }

        int mn = INT_MAX;
        int mx = INT_MIN;
        int n = critical.size();

        if(n>1)
            mx = max(mx, critical[n-1]-critical[0]);

        for(int i=1;i<n;i++) 
        {
            mn = min(mn, critical[i]-critical[i-1]);
        }
        ans[0] = mn==INT_MAX ? -1 : mn;
        ans[1] = mx==INT_MIN ? -1 : mx;
        return ans;
    }
};