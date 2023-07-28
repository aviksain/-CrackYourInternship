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
public:
    int check(TreeNode* root, bool &ans) {
        if(!root) return 0;

        int h1 = check(root->left,ans);
        int h2 = check(root->right,ans);

        if(abs(h1-h2)>1) ans = false;

        return 1+max(h1,h2);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool ans = true;
        check(root,ans);
        return ans;
    }
};





