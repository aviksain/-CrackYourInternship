// Solution 1 (Using map)-------------------->>>>>>>>>>>

class Solution {
private:
    bool isPalindrome(string str) {
        string s = str;
        reverse(str.begin(),str.end());
        return s == str;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ans;

        if(n<2) return ans;

        unordered_map<string,int> mp; 
        for(int i=0; i<n; i++) {
            string s = words[i];
            reverse(s.begin(),s.end());
            mp[s]=i;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<=words[i].size(); j++) {
                string st1 = words[i].substr(0,j); 
                string st2 = words[i].substr(j);               
                 
                if(mp.count(st1) && isPalindrome(st2) && mp[st1] != i) {
                    ans.push_back({i, mp[st1]});    
                }

                if(!st1.empty() && mp.count(st2) && isPalindrome(st1) && mp[st2] != i) {
                    ans.push_back({mp[st2], i});
                }
            }            
        }
        return ans;
    }
};






// Solution 2 (Using Trie) --------------------->>>>>>>>>>>>>>

struct TrieNode {
    int index;
    vector<int> palindromeSuffix;
    TrieNode* children[26] = {NULL};
    TrieNode() {
        index = -1;
    }
};

class Solution {
    bool isPalindrome(string& word, int start, int end) {
        while(start<end){
            if (word[start++] != word[end--]) {
                return false;
            }
        }
        return true;
    }
    
    TrieNode* root = new TrieNode();
    
    void insert(string& word, int idx) {
    	TrieNode* curr = root;
        int n = word.size();
        for(int i=n-1; i>=0; i--) {
            int next = word[i]-'a';
            if (curr->children[next] == nullptr) {
                curr->children[next] = new TrieNode();
            }
            
            if (isPalindrome(word, 0, i)) {
                curr->palindromeSuffix.push_back(idx);
            }
            
            curr = curr->children[next];
        }
        
        curr->index = idx;
        curr->palindromeSuffix.push_back(idx);
    }
    
    void search(string& word, int idx, vector<vector<int>>& ans) {
    	TrieNode* curr = root;
    	
        for(int i=0; i<word.size(); i++) {
            if (curr->index >= 0 && curr->index != idx && isPalindrome(word, i, word.size()-1)) {
                ans.push_back({idx, curr->index});
            }
            
            curr = curr->children[word[i]-'a'];
            // no string exist in reverse, then return
            if (curr == NULL) {
                return;
            }
        }
        
        for(auto it: curr->palindromeSuffix) {
            if (it == idx) {
                continue;
            }
            ans.push_back({idx, it});
        }
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        
        int n = words.size();
        
        for(int i=0; i<n; i++) {
            insert(words[i], i);
        }
        
        for(int i=0; i<n; i++) {
            search(words[i], i, ans);
        }
        return ans;
            
    }
};
