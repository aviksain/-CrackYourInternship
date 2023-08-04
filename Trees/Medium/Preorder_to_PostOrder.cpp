/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/



// Solution 1 ------------------------------>>>>>>>>>>>>>>>>>> 

class Solution {
private:
    Node* func(int pre[], int st, int end) {
        if(st > end) return NULL;
        
        Node* root;
        
        root = newNode(pre[st]);
        
        int idx = st+1;
        while(idx<=end && pre[st] > pre[idx]) idx++;
        
        root->left = func(pre, st+1, idx-1);
        root->right = func(pre, idx, end);
        
        return root;
    }
    
public:
    Node* post_order(int pre[], int size) {
        return func(pre,0,size-1);
    }
};


// Solution 2 ---------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    Node* func(int pre[], int &idx, int n, int mini, int maxi) {
        if(idx == n) return NULL;
        
        if(pre[idx] <= mini || pre[idx] >= maxi) return NULL;
        
        Node* root;
        
        root = newNode(pre[idx++]);
        
        root->left = func(pre, idx, n, mini ,root->data);
        root->right = func(pre, idx, n, root->data, maxi);
        
        return root;
    }
    
public:
    Node* post_order(int pre[], int n) {
        int idx=0;
        return func(pre,idx,n,INT_MIN,INT_MAX);
    }
};
