/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head) return head;
        Node* itr = head;
        while(itr) {
            Node* next = itr->next;
            Node* dup = new Node(itr->val);
            itr->next = dup;
            dup->next = next;
            itr = next;
        }

        itr=head;
        while(itr) {
            if(itr->random == NULL) {
                itr->next->random = NULL;
            }
            else {
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }

        Node* ans = new Node(0);
        Node* dummy = ans;
        itr=head;
        while(itr) {
            dummy->next = itr->next;
            itr->next = itr->next->next;

            dummy = dummy->next;
            itr = itr->next;
        }

        return ans->next;
    }
};