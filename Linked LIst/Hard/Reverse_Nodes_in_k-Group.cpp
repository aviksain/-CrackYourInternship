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
private:
    int findLength(ListNode* head) {
        int len = 0;
        while(head) {
            head = head->next;
            len++;
        }
        return len;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head && !head->next) return head;

        int len = findLength(head);

        ListNode* dummy = new ListNode(-1); 
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur;
        ListNode* nxt;

        while(len >= k) {
            cur = pre->next;
            nxt = cur->next;
            for(int i=1; i<k; i++) {
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = cur->next;
            }
            pre = cur;
            len -= k;
        }
        return dummy->next;
    }
};


