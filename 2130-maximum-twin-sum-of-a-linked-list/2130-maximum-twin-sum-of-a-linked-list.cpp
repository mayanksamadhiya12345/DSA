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
    int pairSum(ListNode* head) {
        vector<int> arr;
        int n=0;
        while(head!=NULL) {
            arr.push_back(head->val);
            n++;
            head=head->next;
        }

        int i=0, j=n-1;
        int ans = INT_MIN;
        while(i<j) {
            ans = max(ans, arr[i]+arr[j]);
            i++;
            j--;
        }
        return ans;
    }
};