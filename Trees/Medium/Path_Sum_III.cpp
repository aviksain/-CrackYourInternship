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


// T.C. -> O(n)
// S.C. -> O(log(n))

class Solution {
private:
    int func(TreeNode* root, long long int targetSum) {
        if(!root) return 0;
        
        int cnt = 0;
        if(targetSum == root->val) {
            cnt++;
        }

        cnt += func(root->left,targetSum-root->val);
        cnt += func(root->right,targetSum-root->val);

        return cnt;
    }

    int totalPaths(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int ans = 0;
        ans += func(root,targetSum);
        ans += totalPaths(root->left,targetSum);
        ans += totalPaths(root->right,targetSum);
        return ans;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        return totalPaths(root,targetSum);
    }
};






