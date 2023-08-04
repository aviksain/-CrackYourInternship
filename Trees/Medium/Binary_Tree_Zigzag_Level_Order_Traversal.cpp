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
    void levelOrder(TreeNode* root, vector<vector<int>> &v, int currLevel) {
        if (root == NULL) {
            return;
        }
        if (v.empty() || currLevel > (v.size() - 1)) {
            v.push_back(vector<int>());
        }
        v[currLevel].push_back(root->val);

        levelOrder(root->left, v, currLevel + 1);
        levelOrder(root->right, v, currLevel + 1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        levelOrder(root, ans, 0);

        for(int i=0; i<ans.size(); i++) {
            if(i%2 != 0) {
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};
