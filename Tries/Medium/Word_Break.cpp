// Recursion (gives TLE) --------------->>>>>>>>>>>>>>>

class Solution {
private:
    bool search(int idx, string word, unordered_set<string>& st) {
        if(idx == word.size()) {
            return true;
        }

        bool ans = false;
        string str = "";

        for(int i=idx; i<word.size(); i++) {
            str += word[i];
            if(st.find(str) != st.end()) {
                ans = ans | search(i+1,word,st);
            }
        }

        return ans;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto it : wordDict) {
            st.insert(it);
        }
        return search(0,s,st);
    }
};




// Using Memoization ------------------>>>>>>>>>>>>>>>>>>

class Solution {
private:
    bool search(int idx, string word, unordered_set<string>& st, vector<int>& dp) {
        if(idx == word.size()) {
            return true;
        }

        if(dp[idx] != -1) return dp[idx];

        bool ans = false;
        string str = "";

        for(int i=idx; i<word.size(); i++) {
            str += word[i];
            if(st.find(str) != st.end()) {
                ans = ans | search(i+1,word,st,dp);
            }
        }

        return dp[idx] = ans;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> dp(s.size(),-1);
        for(auto it : wordDict) {
            st.insert(it);
        }
        return search(0,s,st,dp);
    }
};










// Using Trie (gives TLE)   ----------------->>>>>>>>>>>>>>>>>>


class Solution {
private:
    class Node {
    public:
        Node* children[26];
        bool endOfWord;
        Node() {
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            endOfWord = false;
        }
    };

    Node* root = new Node();

    void insert(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) {
                curr->children[idx] = new Node();
            }
            if(i == word.length()-1) {
                curr->children[idx]->endOfWord = true;
            }

            curr = curr->children[idx];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) {
                return false;
            }
            if(i == word.length()-1 && !curr->children[idx]->endOfWord) {
                return false;
            }

            curr = curr->children[idx];
        }
        return true;
    }

    bool find(string word) {
        if(word.length() == 0) {
            return true;
        }

        for(int i=0; i<word.length(); i++) {
            string s1 = word.substr(0,i+1);
            string s2 = word.substr(i+1);

            if(search(s1) && find(s2)) {
                return true;
            }
        }

        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0; i<wordDict.size(); i++) {
            insert(wordDict[i]);
        }

        return find(s);
    }
};




// Using Trie + Memoization ------------------------>>>>>>>>>>>>>>>>>>>

class Solution {
private:
    class Node {
    public:
        Node* children[26];
        bool endOfWord;
        Node() {
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            endOfWord = false;
        }
    };

    Node* root = new Node();

    void insert(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) {
                curr->children[idx] = new Node();
            }
            if(i == word.length()-1) {
                curr->children[idx]->endOfWord = true;
            }

            curr = curr->children[idx];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) {
                return false;
            }
            if(i == word.length()-1 && !curr->children[idx]->endOfWord) {
                return false;
            }

            curr = curr->children[idx];
        }
        return true;
    }

    bool find(string word, unordered_map<string,bool>& dp) {
        if(word.length() == 0) {
            return true;
        }

        if(dp.find(word) != dp.end()) return dp[word];

        for(int i=0; i<word.length(); i++) {
            string s1 = word.substr(0,i+1);
            string s2 = word.substr(i+1);

            if(search(s1) && find(s2,dp)) {
                return dp[word] = true;
            }
        }

        return dp[word] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0; i<wordDict.size(); i++) {
            insert(wordDict[i]);
        }
        unordered_map<string,bool> dp;
        return find(s,dp);
    }
};


























