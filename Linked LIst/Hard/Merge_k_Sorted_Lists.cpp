// Solution 1 --------------->>>>>>>>>>>>>>>>>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        
        while(temp) {
            ListNode* curr = NULL;
            int value = 1e9;
            int idx = -1;
            for(int i=0; i<lists.size(); i++) {
                ListNode* ptr = lists[i];
                if(ptr && value > ptr->val) {
                    curr = ptr;
                    value = ptr->val;
                    idx = i;
                }
            }
            temp->next = curr;
            temp = temp->next;
            if(idx != -1) {
                ListNode* ptr = lists[idx];
                ptr = ptr->next;
                lists[idx] = ptr;
            }
        } 
        return head->next;
    }
};










// Solution 2 (using priority_queue) --------------->>>>>>>>>>>>>>>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;

        for(auto ptr : lists) if(ptr != NULL) pq.push({ptr->val,ptr});

        while(!pq.empty()) {
            ListNode* ptr = pq.top().second;
            pq.pop();

            if(ptr->next) pq.push({ptr->next->val, ptr->next});
            temp->next = ptr;
            temp = temp->next;
        } 
        return head->next;
    }
};















