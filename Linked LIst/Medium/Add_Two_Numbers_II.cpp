// Solution 1 (Using Stack) -------------->>>>>>>>>>>>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2,ans;

        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        while(!s1.empty() || !s2.empty() || carry) {
            int sum = 0;
            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            
            sum += carry;
            carry = sum/10;
            ans.push(sum%10);
        }

        ListNode* head = new ListNode();
        ListNode* temp = head;
        while(!ans.empty()) {
            ListNode* newnode = new ListNode(ans.top());
            ans.pop();
            temp->next = newnode;
            temp = temp->next;
        }

        return head->next;
    }
};





// Solution 2 (By reverse the list)  --------->>>>>>>>

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

    ListNode* addTwoList(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        int carry=0;
        while(l1 && l2) {
            int x = 0;
            int y = 0;
            if(l1!=NULL){
                x+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                y+=l2->val;
                l2=l2->next;
            }
            int sum = x + y + carry;
            carry = sum/10;
            ListNode* newnode = new ListNode(sum%10);
            temp->next = newnode;
            temp = temp->next;
        }

        while(l1) {
            int sum = l1->val + carry;
            carry = sum/10;
            ListNode* newnode = new ListNode(sum%10);
            temp->next = newnode;
            temp = temp->next;
            l1 = l1->next;
        }

        while(l2) {
            int sum = l2->val + carry;
            carry = sum/10;
            ListNode* newnode = new ListNode(sum%10);
            temp->next = newnode;
            temp = temp->next;
            l2 = l2->next;
        }

        if(carry != 0) {
            ListNode* newnode = new ListNode(carry);
            temp->next = newnode;
            temp = temp->next;
        }

        return head->next;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* revHead1 = reverseList(l1);
        ListNode* revHead2 = reverseList(l2);

        ListNode* head = addTwoList(revHead1,revHead2);

        return reverseList(head);
    }
};
