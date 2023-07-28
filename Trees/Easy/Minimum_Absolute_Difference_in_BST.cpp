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




class Solution {
private:
    void inorder(TreeNode* curr, TreeNode*& prev, int& ans) {
        if (curr == NULL)
            return;
    
        inorder(curr->left, prev, ans);
    
        if (prev != NULL)
            ans = min(curr->val - prev->val, ans);
        prev = curr;
    
        inorder(curr->right, prev, ans);
    }

public:
    int getMinimumDifference(TreeNode* root) {
           
        TreeNode* prev = NULL;
   
        int ans = 1e9;
   
        inorder(root, prev, ans);
   
        return ans;
    }
};
