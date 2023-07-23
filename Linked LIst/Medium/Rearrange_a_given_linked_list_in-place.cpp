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

Node* reverseList(Node* head) {
    if(!head || !head->next) return head;
        
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* findMiddle(Node* head) {
    Node *slow = head;
    Node *fast = head->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
    
Node* inPlace(Node* head) {
    
    Node* mid = findMiddle(head);
    
    Node* head1 = head;
    Node* head2 = mid->next;
    mid->next = NULL;
    
    head2 = reverseList(head2);
    
    Node* dummy = new Node(0); 
    
    Node* curr = dummy;
    while (head1 || head2) {
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    return dummy->next;
}
 
