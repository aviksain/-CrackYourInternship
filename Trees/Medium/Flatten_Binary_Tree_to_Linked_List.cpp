// Using recursion ------------->>>>>>>>>>>

class Solution {
private:
    void solve(TreeNode*& root, TreeNode*& prev) {
        if(!root) return;

        solve(root->right,prev);
        solve(root->left,prev);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        solve(root,prev);
    }
};


// Using Stack ------------------------>>>>>>>>>>>>>>>>

class Solution {
private:
    void solve(TreeNode*& root, TreeNode*& prev) {
        if(!root) return;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            
            if(!st.empty()) {
                node->right = st.top();
            }
            node->left = NULL;
        }
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        solve(root,prev);
    }
};


// Using Morris Traversal ---------------->>>>>>>>>>>>>>>>>>

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while(curr) {
        	TreeNode* prev = curr->left;
        	if(curr->left) {
        		while(prev->right) {
	        		prev = prev->right;
	        	}	
	        	prev->right = curr->right;
	        	curr->right = curr->left;
	        	curr->left = NULL;
        	}
        	curr = curr->right;
        }
    }
};





