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
    void check(TreeNode* root, TreeNode*& prev, TreeNode*& firstNode, TreeNode*& lastNode) {
        if(!root) return;

        check(root->left,prev,firstNode,lastNode);
        if(prev) {
        	if(root->val<prev->val) {
        		if(!firstNode) {
	        		firstNode = prev;
	        	}
	        	lastNode = root;
        	}
        }
        prev = root;
        check(root->right,prev,firstNode,lastNode);
    }   
    
public:
    void recoverTree(TreeNode* root) {

        TreeNode* firstNode = NULL;
        TreeNode* lastNode = NULL;
        TreeNode* prev = NULL;

        check(root,prev,firstNode,lastNode);
        swap(firstNode->val,lastNode->val);
    }
};


