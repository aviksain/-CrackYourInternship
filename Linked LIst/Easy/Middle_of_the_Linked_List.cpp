// Solution 1 --------------------->>>>>>>>>>>>>>>>>

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *curr = head;
        int count = 0;
        while(curr != NULL) {
            count++;
            curr = curr->next;
        }
        curr = head;
        int mid = count/2; 
        int i = 0;
        while(curr != NULL) {
            if(i == mid) {
                return curr;
            }
            i++;
            curr = curr->next;
        }
        return NULL;
    }
};




// Solution 2 ---------------->>>>>>>>>>>>>

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

