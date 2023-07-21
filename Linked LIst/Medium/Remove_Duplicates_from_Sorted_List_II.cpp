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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur = head;
        
        
        while(cur) {
            ListNode* nxt = cur->next;
            if(nxt && cur->val == nxt->val) {
                while(nxt && cur->val == nxt->val) {
                    nxt = nxt->next;
                }
                pre->next = nxt;
                cur = nxt;
            }
            else {
                pre = cur;
                cur = nxt;
            }
        } 

        return dummy->next;
    }
};


