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
    void func(TreeNode* root, int& sum, bool isLeft) {
        if(!root) return;

        if(!root->left && !root->right && isLeft) {
            sum += root->val;
        }

        func(root->left,sum,true);
        func(root->right,sum,false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        func(root,sum,false);
        return sum;
    }
};




