

/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

int cntNodes(struct Node *root) {
    if(!root) return 0;
    
    int cnt = 1;
    cnt += cntNodes(root->left);
    cnt += cntNodes(root->right);
    return cnt;
}

void median(Node *root, int &c, int &k, Node* &store, Node* &prev, bool &flag) {
    if(!root) return;
    
    median(root->left,c,k,store,prev,flag);
    
    if(prev == NULL) {
        c++;
        prev = root;
    }
    else if(c == k) {
        c++;
        store = root;
        flag = true;
        return;
    }
    else if(!flag) {
        c++;
        prev = root;
    }
    
    median(root->right,c,k,store,prev,flag);
}

float findMedian(struct Node *root) {
    int nodes = cntNodes(root);
    
    int k = (nodes/2)+1;
    int c = 1;
    Node* store = NULL;
    Node* prev = NULL;
    bool flag = false;
    
    median(root,c,k,store,prev,flag);
    
    float ans = 0;
    
    if(nodes&1){
        ans = (store->data)*1.0;
    }
    else {
        ans = ((store->data+prev->data)*1.0)/(2*1.0);
    }
    
    return ans;
}










