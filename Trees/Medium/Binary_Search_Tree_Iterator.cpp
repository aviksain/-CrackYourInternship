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
class BSTIterator {
private:
    void inorder(vector<int> &v, TreeNode *root) {
        if(root == NULL) {
            return;
        }
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }
public:
    vector<int> vec;
    int idx = -1;
    BSTIterator(TreeNode* root) {
        vec.push_back(-1);
        inorder(vec,root);
        idx = 0;
    }
    
    int next() {
        idx++;
        return vec[idx];
    }
    
    bool hasNext() {
        if(idx<vec.size()-1) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
