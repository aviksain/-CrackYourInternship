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






// Brute force ----------->>>>>>>>>>>>>>> T.C. -> O(n)

class Solution {
public:
    bool check(TreeNode *root, int minVal, int maxVal) {
        if(root == NULL) {
            return true;
        }

        if(root->val >= maxVal || root->val <= minVal) {
            return false;
        }
        
        bool left = check(root->left,minVal,root->val);
        bool right = check(root->right,root->val,maxVal);
        
        return left && right;
    }

    bool isBST(TreeNode* root){
        return check(root,-1e9,1e9);
    }

    int sumTree(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        int sum = root->val;

        sum += sumTree(root->left);
        sum += sumTree(root->right);
        return sum;
    }

    int maxi=0;
    int maxSumBST(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        if(isBST(root)) {
            maxi = max(maxi,sumTree(root));
        }

        maxSumBST(root->left);
        maxSumBST(root->right);

        return maxi;
    }
};







// Optimal ------------>>>>>>>>>>>  T.C. -> O(n)

class nodeValue {
public:
    int min,max,sum;

    nodeValue(int min,int max,int sum) {
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};

class Solution {
private:
    nodeValue find(TreeNode* root) {
        if(!root) {
            return nodeValue(INT_MAX,INT_MIN,0);
        }

        nodeValue left = find(root->left);
        nodeValue right = find(root->right);

        if(root->val > left.max && root->val < right.min) {
            int sum = root->val + left.sum + right.sum;
            ans = max(ans,sum);
            return nodeValue(min(root->val,left.min),max(root->val,right.max),sum);
        }

        return nodeValue(INT_MIN,INT_MAX,max(left.sum,right.sum));
    }

public:
    int ans = 0;
    int maxSumBST(TreeNode* root) {
        find(root);
        return ans;
    }
};




