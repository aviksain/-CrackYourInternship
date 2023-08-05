class Solution {
private:
    Node* LCA(Node* root, int a, int b) {
        if(!root) 
            return NULL;
        
        if(root->data == a || root->data == b) {
            return root;
        }
        
        Node* left = LCA(root->left,a,b);
        Node* right = LCA(root->right,a,b);
        
        if(left != NULL && right != NULL) {
            return root;
        }
        else if(left == NULL && right == NULL) {
            return NULL;
        }
        else if(left == NULL) {
            return right;
        }
        else {
            return left;
        }
    }
    
    int dist(Node* root, int x) {
        if(!root) {
            return 1e9;
        }
        
        if(root->data == x) {
            return 0;
        }
        
        int left = dist(root->left, x);
        int right = dist(root->right, x);
        
        return min(left, right) + 1;
    }
    
public:
    int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root,a,b);
        
        int dist1 = dist(lca,a);
        int dist2 = dist(lca,b);
        
        return dist1+dist2;
    }
};
