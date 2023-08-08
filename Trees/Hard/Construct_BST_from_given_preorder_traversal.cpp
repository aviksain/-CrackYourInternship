/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// Solution 1 -------------->>>>>>>>>>>>> T.C. -> O(n^2)

class Solution {
private:
    TreeNode* create(int low, int high,vector<int>& preorder) {
        if(low > high) return NULL;

        TreeNode* root = new TreeNode(preorder[low]);

        int idx = low+1;
        while(idx<=high && preorder[low] > preorder[idx]) idx++;

        root->left = create(low+1,idx-1,preorder);
        root->right = create(idx,high,preorder);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return create(0,preorder.size()-1,preorder);
    }
};





// Solution 2 ---------->>>>>>>>>> T.C. -> O(nlog(n))

class Solution {
private:
    TreeNode* create(TreeNode* &root, int data) {
        if(root == NULL) {
            root = new TreeNode(data);
        }
        if(root->val > data) {
            root->left = create(root->left,data);
        }
        if(root->val < data) {
            root->right = create(root->right,data);
        }

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i=0; i<preorder.size(); i++) {
            create(root,preorder[i]);
        }
        return root;
    }
};




// Solution 3 ------------------->>>>>>>>>>>>>>   T.C. -> O(n)

class Solution {
private:
    TreeNode* create(int& idx, int mini, int maxi, int n, vector<int>& preorder) {
        if(idx >= n) 
            return NULL;

        if(preorder[idx] < mini || preorder[idx] > maxi) 
            return NULL;

        TreeNode* root = new TreeNode(preorder[idx++]);

        root->left = create(idx,mini,root->val,n,preorder);

        root->right = create(idx,root->val,maxi,n,preorder);
    
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return create(idx,-1e9,1e9,preorder.size(),preorder);
    }
};

