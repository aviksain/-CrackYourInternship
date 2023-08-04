
class Solution{
private: 
    int preOrder(Node *root, int low, int high) {
        if (root == NULL) {
            return 0;
        }
        
        if(root->data == low && root->data == high) 
            return 1;
    
        int cnt=0;
        if(root->data >= low && root->data <= high) {
            cnt++;
        }
        
        if(root->data < low) {
           cnt += preOrder(root->right,low,high);
        }
        else if(root->data > high) {
            cnt += preOrder(root->left,low,high);
        }
        else {
            cnt += preOrder(root->left,low,high);
            cnt += preOrder(root->right,low,high);
        }
        
        return cnt;
    }
    
public:
    int getCount(Node *root, int low, int high) {
       return preOrder(root,low,high);
    }
};





