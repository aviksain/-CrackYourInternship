// Solution 1 -------------->>>>>>>>>>>>>>>

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        int num = 0;
        int count = 0;
        while(curr != NULL) {
            count++;
            curr = curr->next;
        }
        curr = head;
        while(curr != NULL) {
            count--;
            if(curr->val == 1) {
                num += curr->val * pow(2,count);
            }
            curr = curr->next;
        }
        return num;
    }
};





// Solution 2 ---------------->>>>>>>>>>>>>>

class Solution {
public :
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head != NULL) {
            ans=ans*2 + (head->val);
            head=head->next;
        }
        return ans;
    }
};

