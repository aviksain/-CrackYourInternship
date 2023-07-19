// Solution 1 ------------------->>>>>>>>>>>>>>>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        int cnt1=0, cnt2=0;
        while(curr1 != NULL) {
            curr1 = curr1->next;
            cnt1++;
        }
        while(curr2 != NULL) {
            curr2 = curr2->next;
            cnt2++;
        }

        if(cnt1 > cnt2) {
            int diff = cnt1-cnt2;
            curr1 = headA;
            curr2 = headB;
            while(diff>0) {
                curr1 = curr1->next;
                diff--;
            }
        }
        else {
            int diff = cnt2-cnt1;
            curr1 = headA;
            curr2 = headB;
            while(diff>0) {
                curr2 = curr2->next;
                diff--;
            }
        }

        while(curr1 && curr2 && curr1 != curr2) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        } 

        return curr1;
    }
};






// Solution 2 --------------->>>>>>>>>>>>>>>>


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode *curr1 = headA;
        ListNode *curr2 = headB;
        
        while(curr1 != curr2) {
            if(curr1 == NULL) curr1 = headB;
            else curr1 = curr1->next;
            
            if(curr2 == NULL) curr2 = headA;
            else curr2 = curr2->next;
        }
        return curr1;
    }
};

