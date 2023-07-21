//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node* divide(int N, Node *head){
        Node* odd = new Node(-1);
        Node* even = new Node(-1);
        
        Node* curr1 = odd;
        Node* curr2 = even;
        
        while(head) {
            int num = head->data;
            if(num%2 == 0) {
                curr2->next = head;
                curr2 = curr2->next;
            }
            else {
                curr1->next = head;
                curr1 = curr1->next;
            }
            head = head->next;
        }
        
        curr2->next = odd->next;
        curr1->next = NULL;
        
        return even->next;
    }
};
