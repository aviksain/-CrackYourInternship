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
    void findPath(string str, vector<string>& ans, TreeNode* root) {
        if(!root->left && !root->right) {
            ans.push_back(str);
            return;
        }

        if(root->left) {
            string temp = to_string(root->left->val);
            findPath(str+"->"+temp,ans,root->left);
        }

        if(root->right) {
            string temp = to_string(root->right->val);
            findPath(str+"->"+temp,ans,root->right);
        }

        return;
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        findPath(to_string(root->val),ans,root);
        return ans;
    }
};
