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
    vector<TreeNode*> func(int st, int end) {
        vector<TreeNode*> vec;
        if(st > end) {
            vec.push_back(NULL);
            return vec;
        }

        if(st == end) {
            vec.push_back(new TreeNode(st));
            return vec;
        }

        for(int i=st; i<=end; i++) {
            vector<TreeNode*> leftTrees = func(st,i-1);
            vector<TreeNode*> rightTrees = func(i+1,end);
            for(TreeNode* left : leftTrees) {
                for(TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    vec.push_back(root);
                }
            }
        }
        return vec;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return func(1,n);
    }
};
