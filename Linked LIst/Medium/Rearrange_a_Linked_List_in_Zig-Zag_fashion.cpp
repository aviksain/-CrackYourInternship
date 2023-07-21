/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution {
public:
    Node *zigZag(Node* head) {
        int flag = 0;
        
        Node* curr = head;
        while(curr->next) {
            if(!flag) {
                if(curr->data > curr->next->data) {
                    swap(curr->data,curr->next->data);
                }
            }
            else {
                if(curr->data < curr->next->data) {
                    swap(curr->data,curr->next->data);
                }
            }
            curr = curr->next;
            flag = !flag;
        }
        
        return head;
    }
};


