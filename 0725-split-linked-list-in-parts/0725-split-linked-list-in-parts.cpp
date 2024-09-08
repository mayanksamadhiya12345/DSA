class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while(cur != NULL){
            ++len;
            cur = cur->next;
        }
        vector<ListNode*> res(k,NULL);
        // each will contain len/k element
        // first len%k will contain one extra element
        int sz = len/k;
        int rem = len%k;

        cout<<sz<<" "<<rem;

        ListNode* curr = head;
        ListNode* prev = NULL;
        for(int i=0;i<k;i++){
            res[i] = curr;
            for(int j = 0;j < sz; j++){
                prev = curr;
                curr = curr->next;
            }
            if(rem > 0){
                if(curr != NULL){
                    prev = curr;
                    curr = curr->next;
                    --rem;
                }
            }
            // disconnect the curr and mark new head as prev->next
            if(prev != NULL){
                head = curr;
                prev->next = NULL;
            }
        }
        return res;
    }
};