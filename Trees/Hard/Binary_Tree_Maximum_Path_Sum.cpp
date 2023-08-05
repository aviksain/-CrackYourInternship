/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution {
private:
    void convert(Node* root, Node* &prev, Node* &head) {
        if(!root) return;
        
        convert(root->left,prev,head);
        
        if(prev == NULL) {
            head = root;
        }
        else {
            root->left = prev;
            prev->right = root;
        }
        
        prev = root;
        
        convert(root->right,prev,head);
    }
    
public: 
    Node* bToDLL(Node *root) {
        if(!root) return NULL;
        
        Node* head = NULL;
        Node* prev = NULL;
        convert(root,prev,head);
        
        return head;
    }
};






