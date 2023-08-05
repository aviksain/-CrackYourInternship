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
    /*
        1 ---> not in monitor 
        2 ---> in monitor 
        3 ---> it has camera
    */
private:
    int dfs(TreeNode* root, int& cnt) {
        if(!root) return 2;

        int left = dfs(root->left,cnt);
        int right = dfs(root->right,cnt);

        if(left==2 && right == 2) {
            return 1;
        }
        else if(left==1 || right==1) {
            cnt++;
            return 3;
        }
        return 2;
    }

public:
    int minCameraCover(TreeNode* root) {
        int cnt = 0;
        int value = dfs(root,cnt);
 
        return cnt + (value == 1 ? 1 : 0);
        
    }
};

