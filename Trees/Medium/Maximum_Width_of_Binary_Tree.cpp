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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int maxWidth = 0;

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});
        
        while(!q.empty()) {
            int idx = q.front().second;
            int currSize = q.size();
            int first,last;

            for(int i=0; i<currSize; i++) {
                TreeNode* node = q.front().first;
                int actualIdx = q.front().second-idx;
                q.pop();

                if(i == 0) first = actualIdx;
                if(i == currSize-1) last = actualIdx;

                if(node->left) 
                    q.push({node->left, 2LL*actualIdx + 1});
                if(node->right) 
                    q.push({node->right, 2LL*actualIdx + 2});
            }
            maxWidth = max(maxWidth,last-first+1);
        }
        return maxWidth;
    }
};



