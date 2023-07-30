/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 
class Solution {
private:
    // find the sub nodes at dist k
    void printSubtreeNodes(TreeNode* root, int k, vector<int>& ans) {
        if(!root || k<0) {
            return;
        }
        
        if(k == 0) {
            ans.push_back(root->val);
            return;
        }
        
        printSubtreeNodes(root->left,k-1,ans);
        printSubtreeNodes(root->right,k-1,ans);
    }
    
    // find the target 
    // if the target found then call the function for its child nodes at k th dist
    // backtrack from the target to root, calculate the dist from root to target
    // if root is at kth dist from the target then take it 
    // else if we find our target at left subtree then call the right sub tree with a dist of k-dl-2
    // because we already traveled dl+1 dist 
    int printNodesAtK(TreeNode* root, TreeNode* target, int k, vector<int>& ans) {
        if(root == NULL) {
            return -1;
        }
        
        // if we find our target then print all the sub nodes of the target at dist k
        if(root == target) {
            printSubtreeNodes(root,k,ans);
            return 0;
        }
        
        // find the target in the left 
        int dl = printNodesAtK(root->left,target,k,ans);

        // if we find the target at our left subtree 
        if(dl != -1) {
            if(dl+1 == k) { 
                // if the target is at kth dist fron the root then take the root
                ans.push_back(root->val);
            }
            else { 
                // else call the right sub tree with k-dl-2 dist because we already traveled dl+1 dist
                printSubtreeNodes(root->right,k-dl-2,ans);
            }
            return 1+dl;
        }
        
        int dr = printNodesAtK(root->right,target,k,ans);
        if(dr != -1) {
            if(dr+1 == k) {
                ans.push_back(root->val);
            }
            else {
                printSubtreeNodes(root->left,k-dr-2,ans);
            }
            return 1+dr;
        }
        return -1;
    }


public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        printNodesAtK(root,target,k,ans);
        return ans;
    }
};
