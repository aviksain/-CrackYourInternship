/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Codec {
private:
    void encode(TreeNode* root, string& str) {
        if(!root) {
            str += "#,";
            return;
        }

        str += to_string(root->val) + ",";
        encode(root->left,str);
        encode(root->right,str);
    }
    
    TreeNode* decode(int& idx, string str) {
        if(idx >= str.length()) {
            return NULL;
        }

        if(str[idx] == '#') {
            idx += 2;
            return NULL;
        }

        int num = 0;
        bool negative = false;

        if(str[idx] == '-') {
            negative = true;
            idx++;
        }

        while(str[idx] != ',') {
            num = num*10 + (str[idx]-'0');
            idx++;
        }
        idx++;

        if(negative) {
            num = (-1)*num;
        }

        TreeNode* root = new TreeNode(num);

        root->left = decode(idx,str);
        root->right = decode(idx,str);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        encode(root,str);
        return str;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {
        int idx = 0;
        return decode(idx,str);
    }
};




// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
