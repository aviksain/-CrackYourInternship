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
	TreeNode* buildTree(int preSt, int preEd, int postSt, int postEd, vector<int>& preorder, vector<int>& postorder) {
		if(preSt > preEd) return NULL;
		
		TreeNode* root = new TreeNode(preorder[preSt]);
		
		if(preSt == preEd) return root;
		 
		int idx = postSt;
		while(preorder[preSt+1] != postorder[idx]) idx++;
		 
		int len = idx - postSt + 1;
		 
		root->left = buildTree(preSt+1,preSt+len,postSt,idx,preorder,postorder); 
		root->right = buildTree(preSt+len+1,preEd,idx+1,postEd-1,preorder,postorder);
		return root;
	}

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return buildTree(0,n-1,0,n-1,preorder,postorder);
    }
};








