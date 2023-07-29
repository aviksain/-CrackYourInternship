
class Solution {
private:
    void inOrder(Node* root, Node*& pre, Node*& suc, int key, Node* prev) {
        if(!root) return;
        
        prev = root;
        
        if(key > root->key) {
            pre = root;
            inOrder(root->right,pre,suc,key,prev);
        }
        else if(key < root->key) {
            suc = root;
            inOrder(root->left,pre,suc,key,prev);
        }
        else {
            inOrder(root->left,pre,suc,key,prev);
            inOrder(root->right,pre,suc,key,prev);
        }
        
    }
    
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        Node* prev = NULL;
        inOrder(root,pre,suc,key,prev);
    }
};
