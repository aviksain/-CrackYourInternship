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


