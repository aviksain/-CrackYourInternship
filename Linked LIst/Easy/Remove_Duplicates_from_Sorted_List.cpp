class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
      
        ListNode *prev = head;
        ListNode *curr = head->next;
      
        while(curr->next != NULL) {
            if(prev->val == curr->val) {
                prev->next = curr->next;
                curr = curr->next;
            }
            else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        if(prev->val == curr->val) {
            prev->next = NULL;
        }
        return head;
    }
};
