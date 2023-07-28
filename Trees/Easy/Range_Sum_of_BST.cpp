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
    int sumBST(TreeNode* root, int low, int high, int& rangeSum) {

        if(!root) return rangeSum;

        if(root->val >= low && root->val <= high) {
            rangeSum += root->val;
            sumBST(root->left,low,high,rangeSum);
            sumBST(root->right,low,high,rangeSum);
        }
        
        if(root->val < low) {
            sumBST(root->right,low,high,rangeSum);
        }
        
        if(root->val > high) {
            sumBST(root->left,low,high,rangeSum);
        }
        
        return rangeSum;
    }
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int rangeSum=0;
        return sumBST(root,low,high,rangeSum);
    }
};
