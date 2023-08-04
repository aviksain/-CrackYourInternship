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
    TreeNode* func(TreeNode* root, int& k) {
        if(!root) return NULL;

        TreeNode* left = func(root->left,k);

        if(left) return left;

        k--;
        if(k == 0) return root;

        return func(root->right,k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* temp = func(root,k);
        return temp->val;
    }
};






