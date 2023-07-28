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
	bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        
        if (!root && !subRoot) return true;
          
        if (!root || !subRoot) return false;
            
        if (root->val == subRoot->val) {
                return isIdentical(root->left, subRoot->left) 
                  && isIdentical(root->right, subRoot->right);
        }
        return false;
  	}
  	
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      
        if (!subRoot) return true;
        
        if (!root) return false;
      
        if (root->val == subRoot->val) {
            if (isIdentical(root, subRoot)) {
                return true;
            }
        }
      
        return isSubtree(root->left, subRoot) 
            || isSubtree(root->right, subRoot);
    }
};






