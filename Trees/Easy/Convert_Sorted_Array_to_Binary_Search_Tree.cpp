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
    TreeNode* func(int left, int right, vector<int>& nums) {
        if(left > right) return NULL;

        int mid = left + (right-left)/2;

        TreeNode* newNode = new TreeNode(nums[mid]);

        TreeNode* leftNode = func(left,mid-1,nums);
        newNode->left = leftNode;

        TreeNode* rightNode = func(mid+1,right,nums);
        newNode->right = rightNode;

        return newNode;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(0,nums.size()-1,nums);
    }
};


