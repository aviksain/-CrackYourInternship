// Solution 1 (using queue)-------->>>>>>>>>
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        queue<int> q1, q2;

        ListNode* curr = head;

        while(curr) {
            if(curr->val < x) {
                q1.push(curr->val);
            }
            else {
                q2.push(curr->val);
            }
            curr = curr->next;
        }

        curr = head;

        while(!q1.empty()) {
            curr->val = q1.front();
            q1.pop();
            curr = curr->next;
        }
        while(!q2.empty()) {
            curr->val = q2.front();
            q2.pop();
            curr = curr->next;
        }

        return head;
    }
};




// Solution 2 (using two pointer)   ----------------->>>>>>>>>>>>>


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(0);
        ListNode* l2 = new ListNode(0);

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;


        while(head) {
            if(head->val < x) {
                curr1->next = head;
                curr1 = curr1->next;  
            }
            else {
                curr2->next = head;
                curr2 = curr2->next; 
            }
            head = head->next;
        }

        curr1->next = l2->next;
        curr2->next = NULL;
        return l1->next;
    }
};


