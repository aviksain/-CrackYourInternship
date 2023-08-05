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
    void func(TreeNode* root, int idx, int level, map<int,map<int,priority_queue<int,vector<int>,greater<int>>>>& mp) {
        if(!root) return;

        mp[idx][level].push(root->val);

        func(root->left,idx-1,level+1,mp);
        func(root->right,idx+1,level+1,mp);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        map<int,map<int,priority_queue<int,vector<int>,greater<int>>>> mp;

        func(root,0,0,mp);

        for(auto it1 : mp) {
            vector<int> temp;
            for(auto it2 : it1.second) {
                while(!it2.second.empty()) {
                    temp.push_back(it2.second.top());
                    it2.second.pop();
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};


