class Solution {
public:
    Node* segregate(Node *head) {
        int cnt[3] = {0,0,0};
        
        Node* curr = head;
        while(curr) {
            cnt[curr->data]++;
            curr = curr->next;
        }
        
        int i=0;
        curr = head;
        while(i<3 && curr) {
            if(cnt[i] == 0) i++;
            else {
                curr->data = i;
                curr = curr->next;
                cnt[i]--;
            }
        }
        
        return head;
    }
};
