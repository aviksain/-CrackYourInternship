// Solution 1 (using stack)--------------->>>>>>>>>>>>>


class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        Node* curr = head;
        while(curr) {
            if(curr->child) {
                if(curr->next) st.push(curr->next);
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }
            if(!curr->next) {
                if(!st.empty()) {
                    Node* temp = st.top();
                    st.pop();
                    curr->next = temp;
                    temp->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};





// Solution 2 (Two pointer) ---------------->>>>>>>>>>>>>>>

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* curr = head;
        while(curr) {
            if(curr->child == NULL) {
                curr = curr->next;
            }
            else {
                Node* temp = curr->child;
                while(temp->next) temp = temp->next;
                temp->next = curr->next;
                if(curr->next) curr->next->prev = temp;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
                curr = curr->next;
            }
        }
        return head;
    }
};




