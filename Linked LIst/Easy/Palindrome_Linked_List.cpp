// Solution 1 (Using recursion) ---------->>>>>>>>>>>


class Solution {
public :
    ListNode* left;
    bool check(ListNode* right) {
        if(right == NULL) return true;
        if(!check(right->next)) return false;
        if(left->val != right->val) return false;
        left = left->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        left = head;
        return check(head);
    }
};







// Solution (By reverse the half part) ------------->>>>>>>>>>>>>>>


class Solution {
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        
        while (curr != NULL) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr1 = head;
        ListNode* curr2 = findMiddle(curr1);
        curr2 = reverse(curr2);

        while(curr1 && curr2) {
            if(curr1->val != curr2->val) return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    }
};




