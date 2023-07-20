
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
    
        ListNode *revPrev = NULL, *revNext = NULL;
        ListNode *revSt = NULL, *revEnd = NULL;
    
        int i = 1;
        ListNode* curr = head;
        while (curr && i <= right) {
            if (i < left)
                revPrev = curr;
            if (i == left)
                revSt = curr;
            if (i == right) {
                revEnd = curr;
                revNext = curr->next;
            }
            curr = curr->next;
            i++;
        }
        revEnd->next = NULL;

        revEnd = reverseList(revSt);

        if (revPrev)
            revPrev->next = revEnd;
        else
            head = revEnd;

        revSt->next = revNext;
        return head;
    }
};
