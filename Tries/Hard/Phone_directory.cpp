// Solution 1 (Using map) ------------------------->>>>>>>>>>>>>>>>>>>>>>>





class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        
        set<string> st;
        
        for(int i=0; i<n; i++) {
            st.insert(contact[i]);
        }
        
        vector<vector<string>> ans;
        
        for(int i=0; i<s.size(); i++) {
            vector<string> v;
            for(auto it : st) {
                if(it.substr(0,i+1) == s.substr(0,i+1)) {
                    v.push_back(it);
                }
            }
            
            if(v.size() == 0) {
                v.push_back("0");
            }
            
            ans.push_back(v);
        }
        
        return ans;
        
    }
};








// Solution 2  (Using Trie)  --------------------->>>>>>>>>>>>>>>>>>>




struct TrieNode {
    struct TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        for(int i=0; i<26; i++) {
            child[i] = NULL;
        }
        isEnd = false;
    }
};

class Solution {
private:

	TrieNode* root = new TrieNode();
	
	void insert(string s) {
        TrieNode* curr = root;
        for (int i=0; i<s.length(); i++) {
            if (curr->child[s[i] - 'a'] == NULL) {
                curr->child[s[i] - 'a'] = new TrieNode();
            }
            curr = curr->child[s[i] - 'a'];
        }
        curr->isEnd = true;
    }

    void search(TrieNode* node, string subStr, string currStr, int idx, vector<string>& temp) {
        if (node == NULL) {
            return;
        }

        if (idx > subStr.length() - 1) {
            if (node->isEnd) {
                temp.push_back(currStr);
            }
            for (int i = 0; i < 26; i++) {
                currStr += char('a'+i);
                search(node->child[i], subStr, currStr, idx+1, temp);
                currStr.pop_back();
            }
        }
        else {
            if (node->child[subStr[idx]-'a'] == NULL) {
                return;
            }
            currStr += subStr[idx];
            search(node->child[subStr[idx]-'a'], subStr, currStr, idx+1, temp);
            currStr.pop_back();
        }
    }
    
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        for (int i=0; i<n; i++) {
            insert(contact[i]);
        }

        vector<vector<string>> ans;

        for (int i=0; i<s.length(); i++) {
            vector<string> temp;
            search(root->child[s[0]-'a'], s.substr(0, i+1), string(1,s[0]), 1, temp);
            if (temp.empty()) {
                temp.push_back("0");
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
