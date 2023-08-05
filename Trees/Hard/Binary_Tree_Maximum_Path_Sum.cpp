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
    int func(TreeNode * root, int & maxi) {
        if (root == NULL) return 0;

        int left = max(0, func(root->left, maxi));
        int right = max(0, func(root->right, maxi));
        
        maxi = max(maxi, (left + right)+root->val);
        return max(left, right) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        func(root,maxi);
        return maxi;
    }
};



