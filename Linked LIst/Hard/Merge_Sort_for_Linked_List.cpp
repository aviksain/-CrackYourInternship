/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution {
private:
    Node* findMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
public:
    Node* merge(Node* left, Node* right) {
        if(!left) return right;
        if(!right) return left;
        
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while(left && right) {
            if(left->data > right->data) {
                temp->next = right;
                temp = right;
                right = right->next;
            } 
            else {
                temp->next = left;
                temp = left;
                left = left->next;
            }
        }
        
        if(left) temp->next = left;
        
        if(right) temp->next = right;
        
        return dummy->next;
    }
    
    Node* mergeSort(Node* head) {
        if(!head || !head->next) return head;
        
        Node* mid = findMid(head);
        
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        Node* res = merge(left,right);
        
        return res;
    }
};
